/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Loader
*/

#ifndef LOADER_HPP_
#define LOADER_HPP_

#include <dlfcn.h>
#include <iostream>

template<typename T>
class Loader {
    private:
        void *_lib = nullptr;
        T *(*entry)();
    public:
        T *instance = nullptr;
        Loader(): _lib(nullptr), instance(nullptr) {}
        ~Loader() {reset();}
        void reset()
        {
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;
            }
            if (_lib != nullptr) {
                dlclose(_lib);
                if (dlerror() != NULL)
                    throw(Error(dlerror()));
                _lib = nullptr;
            }

        }
        void load(const std::string &lib)
        {
            _lib = dlopen(lib.c_str(), RTLD_NOW);
            if (dlerror() != NULL)
                throw(Error(dlerror()));
            try {
                entry = reinterpret_cast<T *(*)()>(dlsym(_lib, "entry"));
                instance = entry();
            } catch (Error &e) {
                throw(e);
            }
        }

        T *operator ->() const {
            return (instance);
        }

        T &operator *() const {
            return (*instance);
        }

        T &ref() {
            return *instance;
        }

    protected:
};

#endif /* !LOADER_HPP_ */
