// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2026 Captivus Speluncae
#include "latin.h"
#include "fcitx-utils/keysym.h"
#include <fcitx-utils/key.h>
#include <fcitx/inputcontext.h>
#include <fcitx/inputpanel.h>
#include <fcitx/text.h>

void LatinEngine::keyEvent(const fcitx::InputMethodEntry &entry, fcitx::KeyEvent &keyEvent) {
    FCITX_UNUSED(entry);

    if (keyEvent.isRelease()) {
        return;
    }

    fcitx::Key key = keyEvent.key();

    auto *ic = keyEvent.inputContext();

    if (this->buffer == 0) {
        if (std::find(this->vowels.begin(), this->vowels.end(), key.sym()) != vowels.end()) {
            keyEvent.filterAndAccept();

            this->buffer = key.toString()[0];

            std::string str(1, this->buffer);
            fcitx::Text preedit(str);
            ic->inputPanel().setClientPreedit(preedit);
            ic->updatePreedit();
        }

        return;
    }

    if (std::find(this->vowels.begin(), this->vowels.end(), key.sym()) != vowels.end()) {
        keyEvent.filterAndAccept();

        ic->commitString(std::string(1, this->buffer));

        this->buffer = key.toString()[0];
        fcitx::Text preedit(std::string(1, this->buffer));
        ic->inputPanel().setClientPreedit(preedit);
        ic->updatePreedit();

        return;
    }

    if (key.sym() == FcitxKey_equal) {
        keyEvent.filterAndAccept();
        ic->inputPanel().reset();
        ic->updatePreedit();
        this->commitMacron(ic);
        this->buffer = 0;
        return;
    }

    if (key.sym() == FcitxKey_minus) {
        keyEvent.filterAndAccept();
        ic->inputPanel().reset();
        ic->updatePreedit();
        this->commitBreve(ic);
        this->buffer = 0;
        return;
    }

    ic->inputPanel().reset();
    ic->updatePreedit();
    ic->commitString(std::string(1, this->buffer));
    this->buffer = 0;
    return;
}

FCITX_ADDON_FACTORY(LatinEngineFactory);

void LatinEngine::commitMacron(fcitx::InputContext *ic) {
    switch (this->buffer) {
    case 'a':
        ic->commitString("ā");
        break;
    case 'i':
        ic->commitString("ī");
        break;
    case 'u':
        ic->commitString("ū");
        break;
    case 'e':
        ic->commitString("ē");
        break;
    case 'o':
        ic->commitString("ō");
        break;
    case 'A':
        ic->commitString("Ā");
        break;
    case 'I':
        ic->commitString("Ī");
        break;
    case 'U':
        ic->commitString("Ū");
        break;
    case 'E':
        ic->commitString("Ē");
        break;
    case 'O':
        ic->commitString("Ō");
        break;
    default:
        break;
    }
}
void LatinEngine::commitBreve(fcitx::InputContext *ic) {
    switch (this->buffer) {
    case 'a':
        ic->commitString("ă");
        break;
    case 'i':
        ic->commitString("ĭ");
        break;
    case 'u':
        ic->commitString("ŭ");
        break;
    case 'e':
        ic->commitString("ĕ");
        break;
    case 'o':
        ic->commitString("ŏ");
        break;
    case 'A':
        ic->commitString("Ă");
        break;
    case 'I':
        ic->commitString("Ĭ");
        break;
    case 'U':
        ic->commitString("Ŭ");
        break;
    case 'E':
        ic->commitString("Ĕ");
        break;
    case 'O':
        ic->commitString("Ŏ");
        break;
    default:
        break;
    }
}
