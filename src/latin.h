// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2026 Captivus Speluncae
#ifndef _FCITX5_LATIN_LATIN_H_
#define _FCITX5_LATIN_LATIN_H_

#include <fcitx/addonfactory.h>
#include <fcitx/inputcontext.h>
#include <fcitx/inputmethodengine.h>

class LatinEngine : public fcitx::InputMethodEngineV2 {
    void keyEvent(const fcitx::InputMethodEntry &entry, fcitx::KeyEvent &keyEvent) override;

  private:
    std::vector<FcitxKeySym> vowels = {FcitxKey_a, FcitxKey_A, FcitxKey_i, FcitxKey_I, FcitxKey_u, FcitxKey_U, FcitxKey_e, FcitxKey_E, FcitxKey_o, FcitxKey_O};
    char                     buffer = 0;

    void commitMacron(fcitx::InputContext *ic);
    void commitBreve(fcitx::InputContext *ic);
};

class LatinEngineFactory : public fcitx::AddonFactory {
    fcitx::AddonInstance *create(fcitx::AddonManager *manager) override {
        FCITX_UNUSED(manager);
        return new LatinEngine;
    }
};

#endif
