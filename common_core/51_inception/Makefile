.PHONY: up down start stop restart build logs ps

COMPOSE_PATH = ./srcs

up:
	cd $(COMPOSE_PATH) && docker-compose up --build

down:
	cd $(COMPOSE_PATH) && docker-compose down -v

start:
	cd $(COMPOSE_PATH) && docker-compose start

stop:
	cd $(COMPOSE_PATH) && docker-compose stop

restart: stop start

build:
	cd $(COMPOSE_PATH) && docker-compose up --build

logs:
	cd $(COMPOSE_PATH) && docker-compose logs -f

ps:
	cd $(COMPOSE_PATH) && docker-compose ps
