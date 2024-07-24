#!/bin/bash
set -eo pipefail

# Check if MYSQL_ROOT_PASSWORD is set
if [ -z "$MYSQL_ROOT_PASSWORD" ]; then
    echo "ERROR: MYSQL_ROOT_PASSWORD is not set."
    exit 1
fi

# Initialize the database directory if not already initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing database..."
    mysql_install_db --user=mysql --datadir="/var/lib/mysql"
else
    echo "Database already initialized!"
fi

# Start MySQL in the background for initial setup
mysqld_safe --skip-networking &

sed -i 's/^bind-address\s*=.*/bind-address = 0.0.0.0/' /etc/mysql/mariadb.conf.d/50-server.cnf

# Wait for MySQL to start
until mysqladmin ping &>/dev/null; do
    echo "Waiting for MySQL to start..."
    sleep 1
done

# Secure MySQL Installation
mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}'; FLUSH PRIVILEGES;"
mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.user WHERE User='';"
mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "DROP DATABASE IF EXISTS test;"
mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';"
mysql -uroot -p"$MYSQL_ROOT_PASSWORD" -e "FLUSH PRIVILEGES;"

echo "Importing initial database..."
# SQLコマンドを実行してデータベースとユーザーを作成
mysql -uroot -p"$MYSQL_ROOT_PASSWORD" <<EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;

CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
ALTER USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';

CREATE USER IF NOT EXISTS '$ADMIN_USER'@'%' IDENTIFIED BY '$ADMIN_PASS';
ALTER USER '$ADMIN_USER'@'%' IDENTIFIED BY '$ADMIN_PASS';

GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$ADMIN_USER'@'%';

FLUSH PRIVILEGES;
EOF

# Stop background MySQL server
mysqladmin shutdown -uroot -p"$MYSQL_ROOT_PASSWORD"

# Start MySQL in the foreground
exec mysqld
