/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** Hospital
*/

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

#include "KoalaDoctorList.hpp"
#include "KoalaNurseList.hpp"
#include "SickKoalaList.hpp"

class Hospital {
    public:
        Hospital();
        ~Hospital();
        void addDoctor(KoalaDoctorList *new_doctor);
        void addNurse(KoalaNurseList *new_nurse);
        void addSick(SickKoalaList *new_sick);
        void run();

    protected:
    private:
        KoalaDoctorList *_doctors;
        KoalaNurseList *_nurses;
        SickKoalaList *_sicks;
};

#endif /* !HOSPITAL_HPP_ */
