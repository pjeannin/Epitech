/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD06-pierre.jeannin
** File description:
** Hospital
*/

#include <iostream>
#include "Hospital.hpp"

Hospital::Hospital() : _doctors(NULL), _nurses(NULL), _sicks(NULL)
{
}

Hospital::~Hospital()
{
}

void Hospital::addDoctor(KoalaDoctorList *new_doctor)
{
    if (!_doctors)
        _doctors = new_doctor;
    else {
        if (!_doctors->getFromName(new_doctor->getContent()->getName()))
            return;
        _doctors->append(new_doctor);
    }
    std::cout << "[HOSPITAL] Doctor " << new_doctor->getContent()->getName()
    << " just arrived!" << std::endl;
    new_doctor->getContent()->timeCheck();
}

void Hospital::addNurse(KoalaNurseList *new_nurse)
{
    if (!_nurses)
        _nurses = new_nurse;
    else {
        if (!_nurses->getFromID(new_nurse->getContent()->getID()))
            return;
        _nurses->append(new_nurse);
    }
    std::cout << "[HOSPITAL] Nurse " << new_nurse->getContent()->getID()
    << " just arrived!" << std::endl;
    new_nurse->getContent()->timeCheck();
}

void Hospital::addSick(SickKoalaList *new_koala)
{
    if (!_sicks)
        _sicks = new_koala;
    else {
        if (!_sicks->getFromName(new_koala->getContent()->getName()))
            return;
        _sicks->append(new_koala);
    }
    std::cout << "[HOSPITAL] Patient " << new_koala->getContent()->getName()
    << " just arrived!" << std::endl;
}

void Hospital::run()
{
    std::string drug;
    KoalaDoctorList *doctor = _doctors;
    KoalaNurseList *nurse = _nurses;

    std::cout << "[HOSPITAL] Work starting with:" << std::endl;
    doctor->dump();
    nurse->dump();
    _sicks->dump();
    std::cout << std::endl;
    while (_sicks) {
        if (!doctor)
            doctor = _doctors;
        if (!nurse)
            nurse = _nurses;
        doctor->getContent()->diagnose(_sicks->getContent());
        drug = nurse->getContent()->readReport(_sicks->getContent()->getName()
        + ".report");
        _sicks->getContent()->takeDrug(drug);
        doctor = doctor->getNext();
        nurse = nurse->getNext();
        _sicks = _sicks->getNext();
    }
    while (_nurses != NULL) {
        _nurses->getContent()->timeCheck();
        _nurses = _nurses->getNext();
    }
        while (_doctors != NULL) {
        _doctors->getContent()->timeCheck();
        _doctors = _doctors->getNext();
    }
}