FROM texlive/texlive:latest
CMD bash

ARG DEBIAN_FRONTEND=noninteractive
ENV TERM=xterm-256color
RUn sed -i 's/http:\/\/archive.ubuntu.com/http:\/\/mirror.sjtu.edu.cn/g' /etc/apt/sources.list && \
    apt -y update && \
    apt -y install \
        build-essential \
        cmake \
        libfmt-dev \
        git \
        vim \
        clang-format \
        wget \
        tree \
        zip \
        --no-install-recommends


# FROM = docker search/ docker pull
# cat /etc/issue 查看容器linux版本
# docker images 查看本地所有images
# docker ps 查看运行中容器
# docker run -it --rm -v `pwd`:`pwd` -w `pwd` --myname 'tex' image:oldtag /bin/bash 
# docker commit myname image:newtag
# docker rmi $(docker images -f "dangling=true" -q) 删除<none>:<none>镜像，这些镜像是在build过程中由于同样的Name:Tag而产生的
# docker images | grep '<none>' 检查是否有<none>:<none>