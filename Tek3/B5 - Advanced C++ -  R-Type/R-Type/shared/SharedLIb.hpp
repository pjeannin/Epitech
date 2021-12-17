/*
** EPITECH PROJECT, 2021
** RTYPE
** File description:
** Buy Airpods
*/

#ifndef RTYPE_SHAREDLIB_HPP
#define RTYPE_SHAREDLIB_HPP

#include <string>
#include <iostream>
#include <dlfcn.h>
#include "shared/utils/print.hpp"

#define EXTERN_CLASS_IN_C(class__, lib)   \
extern "C" {                             \
    class__ *entry()                     \
    {                                    \
        return new class__;              \
    }                                    \
    Lib getType()                        \
    {                                    \
        return Lib::lib;                 \
    }                                    \
}

namespace RType {

    enum Lib {};

    template<class T>
    class SharedLib {
    public:
        explicit SharedLib() noexcept : _methods(nullptr), _sharedLib(nullptr) { };
        ~SharedLib() noexcept { reset(); };
        SharedLib(const SharedLib &other) noexcept = delete;
        explicit SharedLib(SharedLib &&other) noexcept = delete;
        SharedLib &operator=(const SharedLib &other) const noexcept = delete;
        SharedLib &operator=(SharedLib &&other) const noexcept = delete;
        void reset() noexcept {
            if (_methods)
                delete _methods;
            if (_sharedLib)
                dlclose(_sharedLib);
            char *error = dlerror();
            if (error) {
                DEBUG_PRINT("SharedLibError: " + std::string(error));
                exit(84);
            }
            _sharedLib = nullptr;
            _methods = nullptr;
        };

        template<typename F>
        F getSym(const std::string &name) const noexcept {
            void *sym = dlsym(_sharedLib, name.c_str());
            char *error = dlerror();

            if (error) {
                DEBUG_PRINT("SharedLibError: " + std::string(error));
                return nullptr;
            }
            return (F)sym;
        };
        const std::function<T *()> openLibFromPath(const std::string &path) noexcept {
            if (!(_sharedLib = dlopen(path.c_str(), RTLD_LAZY))) {
                DEBUG_PRINT("SharedLibError: Can't load library " + path);
                return nullptr;
            }
            return getSym<T *(*)()>("entry");
        };
        bool loadFromPath(const std::string &path, const Lib lib) noexcept {
            auto const constructor = openLibFromPath(path);

            Lib (*getType)() = getSym<Lib (*)()>("getType");
            if (!getType || getType() != lib)
                return false;
            if (!constructor)
                exit(84);
            if (!(_methods = constructor())) {
                std::cerr << "SharedLibError: can't create new class from SharedLib" << std::endl;
                exit(84);
            }
            return true;
        };
        T *getMethods() const noexcept { return _methods; };
    private:
        T *_methods;
        void *_sharedLib;
    };
}

#endif //RTYPE_SHAREDLIB_HPP
