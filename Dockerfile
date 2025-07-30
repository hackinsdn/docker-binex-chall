FROM ubuntu:24.04

ENV user=user
ENV chall_port=1337
ENV chall_name=chall_bof
ENV chall_name_bin=binexp_bof_01
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update
RUN apt install -y iproute2 net-tools
RUN apt install -y socat
RUN apt install -y python3
RUN rm -rf /var/lib/apt/lists/*

COPY public_flag /root/$chall_name/flag
COPY $chall_name /root/$chall_name
COPY docker-entrypoint.sh /docker-entrypoint.sh

WORKDIR /root/$chall_name
EXPOSE $chall_port
EXPOSE 8000
CMD ["/docker-entrypoint.sh"]
