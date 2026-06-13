robocopy "libs\SDL2\lib\x64" "out" "*.dll"
robocopy "libs\SDL2_image\lib\x64" "out" "*.dll"
robocopy "libs\SDL2_ttf\lib\x64" "out" "*.dll"
robocopy "libs\SDL2_mixer\lib\x64" "out" "*.dll"
robocopy "assets" "out\assets" /e
exit 0