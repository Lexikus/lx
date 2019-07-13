#include "input.h"

#include <iostream>

#include "keyboard.h"

Input::Input() {
    input_states_.emplace(Key::Space, State { Key::Space, Action::Release, Modifier::Unknown });
    input_states_.emplace(Key::Apostrophe, State { Key::Apostrophe, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Comma, State { Key::Comma, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Minus, State { Key::Minus, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Period, State { Key::Period, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Slash, State { Key::Slash, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num0, State { Key::Num0, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num1, State { Key::Num1, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num2, State { Key::Num2, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num3, State { Key::Num3, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num4, State { Key::Num4, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num5, State { Key::Num5, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num6, State { Key::Num6, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num7, State { Key::Num7, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num8, State { Key::Num8, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Num9, State { Key::Num9, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Semicolon, State { Key::Semicolon, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Equal, State { Key::Equal, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::A, State { Key::A, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::B, State { Key::B, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::C, State { Key::C, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::D, State { Key::D, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::E, State { Key::E, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F, State { Key::F, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::G, State { Key::G, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::H, State { Key::H, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::I, State { Key::I, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::J, State { Key::J, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::K, State { Key::K, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::L, State { Key::L, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::M, State { Key::M, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::N, State { Key::N, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::O, State { Key::O, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::P, State { Key::P, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Q, State { Key::Q, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::R, State { Key::R, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::S, State { Key::S, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::T, State { Key::T, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::U, State { Key::U, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::V, State { Key::V, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::W, State { Key::W, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::X, State { Key::X, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Y, State { Key::Y, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Z, State { Key::Z, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::LeftBracket, State { Key::LeftBracket, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Backslash, State { Key::Backslash, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::RightBracket, State { Key::RightBracket, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::GraveAccent, State { Key::GraveAccent, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::World1, State { Key::World1, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::World2, State { Key::World2, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Escape, State { Key::Escape, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Enter, State { Key::Enter, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Tab, State { Key::Tab, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Backspace, State { Key::Backspace, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Insert, State { Key::Insert, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Delete, State { Key::Delete, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Right, State { Key::Right, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Left, State { Key::Left, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Down, State { Key::Down, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Up, State { Key::Up, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::PageUp, State { Key::PageUp, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::PageDown, State { Key::PageDown, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Home, State { Key::Home, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::End, State { Key::End, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::CapsLock, State { Key::CapsLock, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::ScrollLock, State { Key::ScrollLock, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::NumLock, State { Key::NumLock, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::PrintScreen, State { Key::PrintScreen, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Pause, State { Key::Pause, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F1, State { Key::F1, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F2, State { Key::F2, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F3, State { Key::F3, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F4, State { Key::F4, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F5, State { Key::F5, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F6, State { Key::F6, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F7, State { Key::F7, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F8, State { Key::F8, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F9, State { Key::F9, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F10, State { Key::F10, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F11, State { Key::F11, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F12, State { Key::F12, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F13, State { Key::F13, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F14, State { Key::F14, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F15, State { Key::F15, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F16, State { Key::F16, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F17, State { Key::F17, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F18, State { Key::F18, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F19, State { Key::F19, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F20, State { Key::F20, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F21, State { Key::F21, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F22, State { Key::F22, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F23, State { Key::F23, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F24, State { Key::F24, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::F25, State { Key::F25, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp0, State { Key::Kp0, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp1, State { Key::Kp1, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp2, State { Key::Kp2, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp3, State { Key::Kp3, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp4, State { Key::Kp4, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp5, State { Key::Kp5, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp6, State { Key::Kp6, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp7, State { Key::Kp7, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp8, State { Key::Kp8, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Kp9, State { Key::Kp9, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpDecimal, State { Key::KpDecimal, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpDivide, State { Key::KpDivide, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpMultiply, State { Key::KpMultiply, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpSubtract, State { Key::KpSubtract, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpAdd, State { Key::KpAdd, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpEnter, State { Key::KpEnter, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::KpEqual, State { Key::KpEqual, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::LeftShift, State { Key::LeftShift, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::LeftControl, State { Key::LeftControl, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::LeftAlt, State { Key::LeftAlt, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::LeftSuper, State { Key::LeftSuper, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::RightShift, State { Key::RightShift, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::RightControl, State { Key::RightControl, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::RightAlt, State { Key::RightAlt, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::RightSuper, State { Key::RightSuper, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Menu, State { Key::Menu, Action::Release, Modifier:: Unknown });
    input_states_.emplace(Key::Unknown, State { Key::Unknown, Action::Release, Modifier:: Unknown });
}

void Input::update(const Key key, const State state) {
    if (input_states_[key].action == Action::Repeat && state.action == Action::Press) {
        return;
    }

    input_states_[key] = state;
}

bool Input::is_key_pressed(Key key) {
    if (input_states_[key].action == Action::Press) {
        input_states_[key].action = Action::Repeat;
        return true;
    }

    return input_states_[key].action == Action::Press;
}

bool Input::is_key_pressed_down(Key key) {
    return input_states_[key].action == Action::Press || input_states_[key].action == Action::Repeat;
}