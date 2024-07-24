FROM debian:bullseye

# ビルド時の引数
ARG MYSQL_DATABASE
ARG MYSQL_USER
ARG MYSQL_PASSWORD
ARG AUTH_KEY

# 必要なパッケージをインストール
RUN apt-get update && apt-get install -y \
    php7.4-fpm \
    php7.4-mysql \
    php7.4-gd \
    php7.4-xml \
    curl \
    unzip \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# PHP-FPM ソケットディレクトリの作成
RUN mkdir -p /run/php && chown www-data:www-data /run/php

# WordPressをダウンロードして解凍
RUN curl -o /tmp/wordpress.tar.gz -SL https://wordpress.org/latest.tar.gz && \
    mkdir -p /var/www/html && \
    tar -xzf /tmp/wordpress.tar.gz -C /var/www/html --strip-components=1 && \
    rm /tmp/wordpress.tar.gz

# WordPressの設定ファイルをコピー
# COPY ./conf/wp-config.php /var/www/html/wp-config.php
COPY ./conf/wp-config.sh /usr/local/bin/wp-config.sh
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY ./conf/wp_setup.sh /usr/local/bin/wp-setup.sh

# パーミッションの設定
RUN chown -R www-data:www-data /var/www/html && \
    chmod -R 755 /var/www/html

# wp-cliをインストール
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp && \
    chmod +x /usr/local/bin/wp-setup.sh && \
    chmod +x /usr/local/bin/wp-config.sh

RUN bash /usr/local/bin/wp-config.sh

EXPOSE 9000
CMD ["php-fpm7.4", "-F"]
