FROM debian:bullseye

# Install MariaDB and clean up in one layer to reduce image size
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /var/cache/apt/*

COPY ./conf/init.sh /init.sh

RUN chmod +x /init.sh

EXPOSE 3306

# Use a specific entrypoint and run the database server in the foreground
ENTRYPOINT ["/init.sh"]
CMD ["mysqld"]
