# Nginxコンテナの作成
FROM debian:bullseye

# 必要なパッケージをインストール
RUN apt-get update && apt-get install -y \
    nginx \
    && rm -rf /var/lib/apt/lists/*

# Nginxの設定ファイルをコピー
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./ssl/server.crt /etc/nginx/ssl/server.crt
COPY ./ssl/server.key /etc/nginx/ssl/server.key

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
