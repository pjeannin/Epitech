#ifndef __MODEL_ANIMATION__
#define __MODEL_ANIMATION__

#include <vector>
#include <string>
#include <raylib.h>

namespace raylib {
    class ModelAnimation : public ::ModelAnimation {
    public:
        ModelAnimation(::ModelAnimation const &model) noexcept;
        ~ModelAnimation() noexcept;
        static std::vector<ModelAnimation> load(std::string const &fileName) noexcept;
        ModelAnimation& operator=(::ModelAnimation const &model) noexcept;
        void unload() noexcept;
        ModelAnimation& update(::Model const &model, int frame) noexcept;
        bool isValid(::Model const &model) const noexcept;
    };
}

#endif  /* __MODEL_ANIMATION__ */
