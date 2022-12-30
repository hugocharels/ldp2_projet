#include "../include.hpp"
#include "EditorDisplay.hpp"
#include "../Elements/MenuElement.hpp"


void EditorDisplay::draw() {
    Text{"Hello editor", Point{500, 60}, 20}.print();
}
