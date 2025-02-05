/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:58:47 by joao-pol          #+#    #+#             */
/*   Updated: 2025/02/03 16:00:37 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <sys/types.h>

Brain::Brain(){
		this->ideas[1] = "Chasing squirrels in the park";
		this->ideas[2] = "Getting belly rubs";
		this->ideas[3] = "Eating treats";
		this->ideas[4] = "Napping in the sun";
		this->ideas[5] = "Playing fetch";
		this->ideas[6] = "Digging a hole in the backyard";
		this->ideas[7] = "Barking at the mailman";
		this->ideas[8] = "Cuddling with my human";
		this->ideas[9] = "Stealing socks";
		this->ideas[10] = "Chewing on a favorite toy";
		this->ideas[11] = "Going for a walk";
		this->ideas[12] = "Begging for food";
		this->ideas[13] = "Jumping on the bed";
		this->ideas[14] = "Watching birds through the window";
		this->ideas[15] = "Running in circles";
		this->ideas[16] = "Rolling in something smelly";
		this->ideas[17] = "Getting a bath";
		this->ideas[18] = "Playing tug-of-war";
		this->ideas[19] = "Sniffing everything";
		this->ideas[20] = "Marking my territory";
		this->ideas[21] = "Catching a frisbee";
		this->ideas[22] = "Learning a new trick";
		this->ideas[23] = "Chasing my tail";
		this->ideas[24] = "Sleeping on the couch";
		this->ideas[25] = "Getting pets";
		this->ideas[26] = "Exploring new smells";
		this->ideas[27] = "Barking at other dogs";
		this->ideas[28] = "Going for a car ride";
		this->ideas[29] = "Begging for table scraps";
		this->ideas[30] = "Playing with other dogs";
		this->ideas[31] = "Hunting imaginary prey";
		this->ideas[32] = "Scratching an itch";
		this->ideas[33] = "Making puppy eyes";
		this->ideas[34] = "Guarding the house";
		this->ideas[35] = "Playing hide and seek";
		this->ideas[36] = "Jumping in puddles";
		this->ideas[37] = "Chasing laser pointers";
		this->ideas[38] = "Getting excited when my human comes home";
		this->ideas[39] = "Dreaming of endless treats";
		this->ideas[40] = "Taking a lazy afternoon nap";
		this->ideas[41] = "Playing with a squeaky toy";
		this->ideas[42] = "Watching TV";
		this->ideas[43] = "Getting groomed";
		this->ideas[44] = "Exploring the garden";
		this->ideas[45] = "Making friends with the neighborhood cats";
		this->ideas[46] = "Solving puzzle toys";
		this->ideas[47] = "Enjoying a good stretch";
		this->ideas[48] = "Waiting by the door for my human";
		this->ideas[49] = "Chewing on a bone";
		this->ideas[50] = "Running on the beach";
		this->ideas[51] = "Playing in the snow";
		this->ideas[52] = "Getting belly scratches";
		this->ideas[53] = "Watching squirrels from the window";
		this->ideas[54] = "Learning new commands";
		this->ideas[55] = "Playing with water";
		this->ideas[56] = "Sneaking onto the bed";
		this->ideas[57] = "Protecting my family";
		this->ideas[58] = "Enjoying a car ride";
		this->ideas[59] = "Playing tug with a rope";
		this->ideas[60] = "Chasing bubbles";
		this->ideas[61] = "Getting excited about walk time";
		this->ideas[62] = "Snuggling in a warm blanket";
		this->ideas[63] = "Playing with other pets";
		this->ideas[64] = "Exploring new territories";
		this->ideas[65] = "Getting treats for being good";
		this->ideas[66] = "Watching birds fly";
		this->ideas[67] = "Running through sprinklers";
		this->ideas[68] = "Enjoying a good back scratch";
		this->ideas[69] = "Playing fetch in the park";
		this->ideas[70] = "Dreaming of adventures";
		this->ideas[71] = "Getting attention from everyone";
		this->ideas[72] = "Chasing butterflies";
		this->ideas[73] = "Learning tricks for treats";
		this->ideas[74] = "Enjoying a lazy Sunday";
		this->ideas[75] = "Playing with dog friends";
		this->ideas[76] = "Getting excited about dinner time";
		this->ideas[77] = "Exploring hiking trails";
		this->ideas[78] = "Watching the world go by";
		this->ideas[79] = "Playing in the backyard";
		this->ideas[80] = "Getting brushed";
		this->ideas[81] = "Chasing a ball";
		this->ideas[82] = "Enjoying a good massage";
		this->ideas[83] = "Playing hide and seek with toys";
		this->ideas[84] = "Dreaming of endless playtime";
		this->ideas[85] = "Getting excited about walks";
		this->ideas[86] = "Exploring new environments";
		this->ideas[87] = "Playing with puzzle feeders";
		this->ideas[88] = "Enjoying cuddle time";
		this->ideas[89] = "Chasing shadows";
		this->ideas[90] = "Getting treats for being cute";
		this->ideas[91] = "Playing in autumn leaves";
		this->ideas[92] = "Watching the sunset";
		this->ideas[93] = "Getting belly rubs all day";
		this->ideas[94] = "Exploring the neighborhood";
		this->ideas[95] = "Playing with new toys";
		this->ideas[96] = "Dreaming of tasty meals";
		this->ideas[97] = "Watching the world go by";
		this->ideas[98] = "Playing in the backyard";
		this->ideas[99] = "Getting brushed";
		std::cout << "Brain Created" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain died" << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (uint i = 0 ; i < this->n_idea; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

