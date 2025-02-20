#include "main.h"

#include "Application.h"

#include "../python/Py.h"

Status Prologue()
{
    LOG("On Prologue");

    if (Py::Initialize() == Status::FAILURE) return Status::FAILURE;

    Application::Initialize();

    return Status::SUCCESS;
}

int Main()
{
    LOG("On Main");

    return Application::Execute();
}

void Epilogue()
{
    LOG("On Epilogue");

    Py::Finalize();
}

int main(int argc, char* argv[]){
    int result;
    args = {argc, argv};

    result = static_cast<int>(Prologue());
    if (result == static_cast<int>(Status::SUCCESS)) result = Main();
    Epilogue();

    return result;
}
