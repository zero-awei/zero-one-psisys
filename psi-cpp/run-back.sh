#!/bin/bash
#check parameters
if [ $# == 0 ]
then
  echo -e "\nThe startup parameters are incorrect. Refer to the following instructions\n"
  echo "Usage: $0 excuteabfile na=? ns=? ip=? sn=? [options]"
  echo "Options:"
  echo "na: nacos server host and port. na=43.138.51.248:8848"
  echo "ns: nacos server namespace.  ns=7fc50d88-3410-44a3-acff-9108d2bfe2b2"
  echo "ip: register ip.  ip=172.28.6.229"
  echo "sn: register service name.  sn=psi-c1"
  echo "sp: server port. example sp=8090"
  echo "du: mysql database username.  du=root"
  echo "dp: mysql database password.  dp=psitxms9527"
  echo "dn: mysql database dbname.  dn=zopsi_sys"
  echo "dh: mysql database host.  dh=43.138.223.223"
  echo "dP: mysql database port.  dP=3306"
  echo "dm: mysql database pool maxsize. example dm=25"
  echo ""
  exit 1
fi
#add dynamic lib serach path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../lib
#start server
nohup ./$* >logs.log 2>&1 &
