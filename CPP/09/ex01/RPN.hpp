/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:01:06 by nponchon          #+#    #+#             */
/*   Updated: 2025/03/21 13:01:47 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <stack>
# include <sstream>
# include <stdlib.h>

class RPN {
	private:
		static std::stack<int>	_stack;

		RPN();
		RPN(const RPN &r);
		RPN &operator=(const RPN &r);

	public:
		~RPN();

		static void processInput(std::string &input);
};

#endif
