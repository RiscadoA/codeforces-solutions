# Shell environment for development on NixOS
{ pkgs ? import <nixpkgs> {} }: with pkgs; mkShell {
  nativeBuildInputs = [
    gcc
    python
  ];
}
