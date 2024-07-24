#!/bin/bash
set -e
sleep 5
# WordPressの設定を行う
wp core install --path=/var/www/html --url="https://localhost" --title="dtakamat's blog" --admin_user="${DOCK_USER}" --admin_password="${DOCK_PASSWORD}" --admin_email="you@example.com" --skip-email --allow-root

# 必要なプラグインのインストールと有効化
wp plugin install akismet --activate --path=/var/www/html --allow-root
wp plugin install jetpack --activate --path=/var/www/html --allow-root

echo "WordPress setup completed."
