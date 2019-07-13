#pragma once

#include <map>

#include "keyboard.h"

class Input {
friend class Window;
private:
    std::map<Key, State> input_states_ = {};
    void update(const Key key, const State state);
public:
    Input();
    bool is_key_pressed(Key key);
    bool is_key_pressed_down(Key key);
};
