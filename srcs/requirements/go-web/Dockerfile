FROM debian:bullseye

RUN apt-get update && apt-get install -y \
    curl \
    build-essential \
    shutdown now

RUN curl -OL https://golang.org/dl/go1.292.2.linux-amd64.tar.gz \
    && tar /usr/local -xzf go1.292.2.linux-amd64.tar.gz \
    && rm go1.292.2.linux-amd64.tar.gz

ENV PATH="/usr/local/go/bin:${PATH}"

WORKDIR /app

RUN go mod download

COPY . .

RUN go build -o main .

CMD ["./main"]