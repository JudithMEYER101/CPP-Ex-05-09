/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:37:55 by armeyer           #+#    #+#             */
/*   Updated: 2025/04/09 10:43:40 by armeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
    std::cout << "\n-----Serialization ex01----- \n\n"<< std::endl;
    std::cout << "\n-----Creating billy----- \n\n"<< std::endl;
	Data	*billy = new Data;

	billy->age = 21;
    billy->height = 180;
    billy->moneyCount = 42;
	billy->wish = "Peace and love upon all";

	std::cout << "Billy: " << std::endl;
	std::cout << "\tage: " << billy->age << std::endl;
    std::cout << "\theight: " << billy->height << " cm" << std::endl;
    std::cout << "\tmoney owned: " << billy->moneyCount << " $ " << std::endl;
	std::cout << "\twish: " << billy->wish << std::endl;
    std::cout << "\t++Original pointer: " << billy << "++" << std::endl;
    
	std::cout << std::endl;
    std::cout << "Serializing billy"<< std::endl;
	uintptr_t	billySeri = Serializer::serialize(billy);
	std::cout << "BillySerialized (where billy is stored): " << billySeri << std::endl;
    std::cout << "BillySerialized in exadecimal: " << std::hex << billySeri << std::dec << std::endl;
    std::cout << "BillySerialized adress (where the uintptr pointing billy is stored): " << &billySeri << std::endl;

	std::cout << std::endl;
    std::cout << "Deserializing billy"<< std::endl;
	Data	*billyDeSeri = Serializer::deserialize(billySeri);
	std::cout << "BillyDeSeri: " << std::endl;
	std::cout << "\tage: " << billyDeSeri->age << std::endl;
    std::cout << "\theight: " << billyDeSeri->height << " cm" << std::endl;
    std::cout << "\tmoney owned: " << billyDeSeri->moneyCount << " $" << std::endl;
	std::cout << "\twish: " << billyDeSeri->wish << std::endl;
    std::cout << "\t++Deserialized pointer: " << billyDeSeri << "++" << std::endl;
	delete billy;
    std::cout << "billy has been deleted"<< std::endl;

    Data	*elon = new Data;
    std::cout << "\n-----Creating Elon----- \n\n"<< std::endl;
	elon->age = 53;
    elon->height = 188;
    elon->moneyCount = 330000000000;
	elon->wish = "Convert hate and war into $";

	std::cout << "Elon: " << std::endl;
	std::cout << "\tage: " << elon->age << std::endl;
    std::cout << "\theight: " << elon->height << " cm" << std::endl;
    std::cout << "\tmoney owned: " << elon->moneyCount << " $ " << std::endl;
	std::cout << "\twish: " << elon->wish << std::endl;
    std::cout << "\t++Original pointer: " << elon << "++" << std::endl;
	std::cout << std::endl;

    std::cout << "Serializing Elon"<< std::endl;
	uintptr_t	elonSeri = Serializer::serialize(elon);
	std::cout << "ElonSerialized: " << elonSeri << std::endl;
    std::cout << "ElonSerialized in exadecimal: " << std::hex << elonSeri << std::dec << std::endl;
    std::cout << "ElonSerialized adress: " << &elonSeri << std::endl;

	std::cout << std::endl;
    std::cout << "Deserializing Elon"<< std::endl;
	Data	*elonDeSeri = Serializer::deserialize(elonSeri);
	std::cout << "ElonDeSeri: " << std::endl;
	std::cout << "\tage: " << elonDeSeri->age << std::endl;
    std::cout << "\theight: " << elonDeSeri->height << " cm" << std::endl;
    std::cout << "\tmoney owned: " << elonDeSeri->moneyCount << " $" << std::endl;
	std::cout << "\twish: " << elonDeSeri->wish << std::endl;
    std::cout << "\t++Deserialized pointer: " << elonDeSeri << "++" << std::endl;

	delete elon;
    std::cout << "Elon has been deleted"<< std::endl;
    std::cout << "\n-----Creating Both----- \n\n"<< std::endl;
    Data	*billy2 = new Data;

	billy2->age = 21;
    billy2->height = 180;
    billy2->moneyCount = 42;
	billy2->wish = "Peace and love upon all";
    
    Data	*elon2 = new Data;
	elon2->age = 53;
    elon2->height = 188;
    elon2->moneyCount = 330000000000;
	elon2->wish = "Convert hate and war into $";
    std::cout << "++Original pointer of billy2: " << billy2 << "++" << std::endl;
    std::cout << "++Original pointer of elon2: " << elon2 << "++\n" << std::endl;
    std::cout << "Serializing both: " << std::endl;
    uintptr_t	billy2Seri = Serializer::serialize(billy2);
    uintptr_t	elon2Seri = Serializer::serialize(elon2);
    std::cout << "Billy2Serialized: " << billy2Seri << std::endl;
    std::cout << "Billy2Serialized adress: " << &billy2Seri << "\n" << std::endl;
    std::cout << "Elon2Serialized: " << elon2Seri << std::endl;
    std::cout << "Elon2Serialized adress: " << &elon2Seri << "\n" << std::endl;
    std::cout << "Deserializing both: " << &elon2Seri << "\n" << std::endl;
    Data	*elon2DeSeri = Serializer::deserialize(elon2Seri);
    Data	*billy2DeSeri = Serializer::deserialize(billy2Seri);
    std::cout << "++Deserialized pointer of billy2: " << billy2DeSeri << "++" << std::endl;
    std::cout << "++Deserialized pointer elon2: " << elon2DeSeri << "++\n" << std::endl;
    std::cout << "Deleting both: " << std::endl;
    delete billy2;
    delete elon2;
	return 0;
}
