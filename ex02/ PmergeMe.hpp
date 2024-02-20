/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PmergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:05:16 by rrask             #+#    #+#             */
/*   Updated: 2024/02/20 17:50:58 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe {
	private:
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
	public:
		PmergeMe();
		~PmergeMe();
};

#endif