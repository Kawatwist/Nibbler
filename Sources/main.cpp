/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <lomasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:49:49 by lomasse           #+#    #+#             */
/*   Updated: 2020/10/21 17:10:11 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Game.hpp"

int     main(int argc, char **argv)
{

    Game    *Snake = new Game(20, 20);

    Snake->Snake();
    delete Snake;
    return (1);
}