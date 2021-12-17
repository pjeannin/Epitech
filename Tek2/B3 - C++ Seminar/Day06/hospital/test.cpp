/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** test
*/

#include <stdlib.h>
#include <iostream>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"
#include "Hospital.hpp"

int main(void)
{
    srandom(42);

    KoalaDoctor cox("Cox");
    KoalaDoctor house("Hourse");
    KoalaDoctor tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);

    KoalaNurse ratched(1);
    KoalaNurse betty(2);
    KoalaNurseList nurse1(&ratched);
    KoalaNurseList nurse2(&betty);

    SickKoala cancer("Ganepar");
    SickKoala gangrene("Scarface");
    SickKoala measles("RedFace");
    SickKoala smallpox("Varia");
    SickKoala fracture("Falter");
    SickKoalaList sick1(&cancer);
    SickKoalaList sick2(&gangrene);
    SickKoalaList sick3(&measles);
    SickKoalaList sick4(&smallpox);
    SickKoalaList sick5(&fracture);

    Hospital bellevue;

    bellevue.addDoctor(&doc1);
    bellevue.addDoctor(&doc2);
    bellevue.addDoctor(&doc3);
    bellevue.addSick(&sick1);
    bellevue.addSick(&sick2);
    bellevue.addSick(&sick3);
    bellevue.addSick(&sick4);
    bellevue.addSick(&sick5);
    bellevue.addNurse(&nurse1);
    bellevue.addNurse(&nurse2);
    bellevue.addSick(&sick4);

    bellevue.run();

    if( nurse1.isEnd() && sick1.isEnd() && doc1.isEnd())
        std::cout << "Lists cleaned up." << std::endl;
    else
        std::cerr << "You fail ! Boo !" << std::endl; return (0);

    return (0);
}