FROM openjdk:8
MAINTAINER 01star
ADD target/psi-gateway-1.0.0-SNAPSHOT.jar app.jar
CMD java -jar app.jar --spring.cloud.nacos.discovery.ip=8.130.23.223 --spring.profiles.active=test --logging.file.path=/tmp/logs/spring-boot
