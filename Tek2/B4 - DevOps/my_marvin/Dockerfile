FROM jenkins/jenkins

ENV JENKINS_HOME /var/jenkins_home
ENV USER_CHOCOLATEEN_PASSWORD chocolat
ENV USER_VAUGIE_G_PASSWORD vaugie
ENV USER_I_DONT_KNOW_PASSWORD dontknow
ENV USER_NASSO_PASSWORD nasso
COPY my_marvin.yml /var/jenkins_home
COPY job_dsl.groovy /var/jenkins_home
COPY plugins.txt /usr/share/jenkins/ref/plugins.txt

ARG JAVA_OPTS
ENV JAVA_OPTS "-Djenkins.install.runSetupWizard=false ${JAVA_OPTS:-}"

RUN xargs /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt