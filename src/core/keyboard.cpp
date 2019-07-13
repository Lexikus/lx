#include "keyboard.h"

State::State(Key _key, Action _action, Modifier _modifier):
    key { _key }, action { _action }, modifier { _modifier } { }

Key get_key_from_keycode(int scancode) {
    switch (scancode) {
        case -1: return Key::Unknown;
        case 32: return Key::Space;
        case 39: return Key::Apostrophe;
        case 44: return Key::Comma;
        case 45: return Key::Minus;
        case 46: return Key::Period;
        case 47: return Key::Slash;
        case 48: return Key::Num0;
        case 49: return Key::Num1;
        case 50: return Key::Num2;
        case 51: return Key::Num3;
        case 52: return Key::Num4;
        case 53: return Key::Num5;
        case 54: return Key::Num6;
        case 55: return Key::Num7;
        case 56: return Key::Num8;
        case 57: return Key::Num9;
        case 59: return Key::Semicolon;
        case 61: return Key::Equal;
        case 65: return Key::A;
        case 66: return Key::B;
        case 67: return Key::C;
        case 68: return Key::D;
        case 69: return Key::E;
        case 70: return Key::F;
        case 71: return Key::G;
        case 72: return Key::H;
        case 73: return Key::I;
        case 74: return Key::J;
        case 75: return Key::K;
        case 76: return Key::L;
        case 77: return Key::M;
        case 78: return Key::N;
        case 79: return Key::O;
        case 80: return Key::P;
        case 81: return Key::Q;
        case 82: return Key::R;
        case 83: return Key::S;
        case 84: return Key::T;
        case 85: return Key::U;
        case 86: return Key::V;
        case 87: return Key::W;
        case 88: return Key::X;
        case 89: return Key::Y;
        case 90: return Key::Z;
        case 91: return Key::LeftBracket;
        case 92: return Key::Backslash;
        case 93: return Key::RightBracket;
        case 96: return Key::GraveAccent;
        case 161: return Key::World1;
        case 162: return Key::World2;
        case 256: return Key::Escape;
        case 257: return Key::Enter;
        case 258: return Key::Tab;
        case 259: return Key::Backspace;
        case 260: return Key::Insert;
        case 261: return Key::Delete;
        case 262: return Key::Right;
        case 263: return Key::Left;
        case 264: return Key::Down;
        case 265: return Key::Up;
        case 266: return Key::PageUp;
        case 267: return Key::PageDown;
        case 268: return Key::Home;
        case 269: return Key::End;
        case 280: return Key::CapsLock;
        case 281: return Key::ScrollLock;
        case 282: return Key::NumLock;
        case 283: return Key::PrintScreen;
        case 284: return Key::Pause;
        case 290: return Key::F1;
        case 291: return Key::F2;
        case 292: return Key::F3;
        case 293: return Key::F4;
        case 294: return Key::F5;
        case 295: return Key::F6;
        case 296: return Key::F7;
        case 297: return Key::F8;
        case 298: return Key::F9;
        case 299: return Key::F10;
        case 300: return Key::F11;
        case 301: return Key::F12;
        case 302: return Key::F13;
        case 303: return Key::F14;
        case 304: return Key::F15;
        case 305: return Key::F16;
        case 306: return Key::F17;
        case 307: return Key::F18;
        case 308: return Key::F19;
        case 309: return Key::F20;
        case 310: return Key::F21;
        case 311: return Key::F22;
        case 312: return Key::F23;
        case 313: return Key::F24;
        case 314: return Key::F25;
        case 320: return Key::Kp0;
        case 321: return Key::Kp1;
        case 322: return Key::Kp2;
        case 323: return Key::Kp3;
        case 324: return Key::Kp4;
        case 325: return Key::Kp5;
        case 326: return Key::Kp6;
        case 327: return Key::Kp7;
        case 328: return Key::Kp8;
        case 329: return Key::Kp9;
        case 330: return Key::KpDecimal;
        case 331: return Key::KpDivide;
        case 332: return Key::KpMultiply;
        case 333: return Key::KpSubtract;
        case 334: return Key::KpAdd;
        case 335: return Key::KpEnter;
        case 336: return Key::KpEqual;
        case 340: return Key::LeftShift;
        case 341: return Key::LeftControl;
        case 342: return Key::LeftAlt;
        case 343: return Key::LeftSuper;
        case 344: return Key::RightShift;
        case 345: return Key::RightControl;
        case 346: return Key::RightAlt;
        case 347: return Key::RightSuper;
        case 348: return Key::Menu;
        default: return Key::Unknown;
    }
}

Action get_action_from_actioncode(int actioncode) {
    switch (actioncode) {
        case 0: return Action::Release;
        case 1: return Action::Press;
        case 2: return Action::Repeat;
        default: return Action::Release;
    }
}

Modifier get_modifier_from_modifercode(int modifiercode) {
    switch (modifiercode) {
        case 1: return Modifier::Shift;
        case 2: return Modifier::Control;
        case 4: return Modifier::Alt;
        case 8: return Modifier::Super;
        case 10: return Modifier::CapsLock;
        case 20: return Modifier::NumLock;
        default: return Modifier::Unknown;
    }
}
