# Fcitx5 addon for typing macron and breve quickly

Type a= for ā.
Type a- for ă.

## Install

Use cmake:
```sh
mkdir -p build
cmake -B build
cd build
make
sudo make install
```

Use flake:
```nix
inputs.latin.url = "github:anhphan156/fcitx5-latin";
```

Then:
```nix
i18n.inputMethod = {
  fcitx5 = {
    addons = [
      inputs.latin.packages."x86_64-linux".default
    ];
  };
};
```
