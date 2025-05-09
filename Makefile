# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 13:10:42 by nponchon          #+#    #+#              #
#    Updated: 2025/05/09 13:19:14 by nponchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

up:
	docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker compose -f ./srcs/docker-compose.yml down --remove-orphans
	docker volume rm $(docker volume ls)
	docker image prune -f

re:
	$(MAKE) down
	$(MAKE) up

clean:
	docker compose -f ./srcs/docker-compose.yml down --remove-orphans --rmi all --volumes
	docker volume prune


fclean:
	$(MAKE) clean