FROM openjdk:8
MAINTAINER 01star
ADD target/psi-sysmanagement-1.0.0-SNAPSHOT.jar app.jar
CMD java -jar app.jar --spring.cloud.nacos.discovery.ip=47.113.200.198 --spring.profiles.active=test --logging.file.path=/tmp/logs/spring-boot
