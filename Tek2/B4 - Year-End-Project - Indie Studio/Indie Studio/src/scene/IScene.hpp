/*
** EPITECH PROJECT, 2021
** IScene
** File description:
** IScene
*/

#ifndef __ISCENE__
#define __ISCENE__

class Core;

class IScene {
public:
    virtual ~IScene() noexcept = 0;
    virtual void loop(Core &core) noexcept = 0;
private:

};

#endif /* __ISCENE__ */
