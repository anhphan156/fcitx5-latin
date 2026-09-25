{
  pkgs,
  lib,
  config,
  ...
}:
{
  # devenv.sh/packages/
  packages = with pkgs; [
    fcitx5
    cmake
  ];

  # devenv.sh/languages/
  languages = {
    cplusplus.enable = true;
  };

  # See full reference at https://devenv.sh/reference/options/
}
