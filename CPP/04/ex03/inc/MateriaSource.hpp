/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:55:32 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/20 12:47:44 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materiaSource);
		~MateriaSource();

		MateriaSource &operator=(const MateriaSource &materiaSource);

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};

#endif
