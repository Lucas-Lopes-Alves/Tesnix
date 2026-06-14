FROM luckys2008/tesnix:v3.2

RUN touch /root/.bashrc \
&& echo "PS1='\[\e[0;32m\]\u@\h:\w\$\[\e[0m\] '" >> /root/.bashrc \
&& rm -rf /var/lib/apt/lists/*

WORKDIR /tesnix

ENTRYPOINT [ "bash" ]