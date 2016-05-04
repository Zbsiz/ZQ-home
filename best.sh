#!/bin/bash

apt update 1>/dev/null
apt -y upgrade 1>/dev/null

#echo "
#---- 追加部分 ----
#net.ipv6.conf.all.disable_ipv6 = 1
#net.ipv6.conf.default.disable_ipv6 = 1
#net.ipv6.conf.lo.disable_ipv6 = 1
#net.ipv6.conf.eth0.disable_ipv6 = 1
#net.ipv4.tcp_fin_timeout = 360" >> /etc/sysctl.conf
