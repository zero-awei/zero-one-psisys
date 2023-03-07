FROM openjdk:8
MAINTAINER 01star
ADD target/psi-login-1.0.0-SNAPSHOT.jar app.jar
CMD java -Xms64m -Xmx64m -jar app.jar --spring.cloud.nacos.discovery.ip=101.132.238.119 --spring.profiles.active=test --logging.file.path=/tmp/logs/spring-boot
