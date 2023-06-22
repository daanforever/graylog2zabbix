FROM alpine:3.18.2
RUN apk add fmt libstdc++ gcompat zabbix-utils
ADD bin/relay /usr/local/bin/
CMD ["/usr/local/bin/relay"]

