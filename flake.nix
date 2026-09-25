{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs =
    { nixpkgs, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
    in
    {
      packages.${system}.default = pkgs.callPackage (
        {
          lib,
          stdenv,
          cmake,
          fcitx5,
        }:

        stdenv.mkDerivation {
          pname = "fcitx5-latin";
          version = "0.1.0";

          src = ./.;
          nativeBuildInputs = [
            cmake
          ];

          buildInputs = [
            fcitx5
          ];

          dontWrapQtApps = true;

          meta = {
            description = "Latin macron and breve input for fcitx5";
            homepage = "https://github.com/anhphan156/fcitx5-latin";
            license = lib.licenses.bsd3;
            platforms = lib.platforms.linux;
          };
        }
      ) { };
    };
}
