#include <imgui.h>
#include <../../imgui/backends/imgui_impl_glfw.h>
#include <../../imgui/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <string>

int main(int argc, char** argv) {
    // Initialize GLFW
    if (!glfwInit())
        return 1;

    // Create a GLFW window
    // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    // glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow* window = glfwCreateWindow(1280, 720, "ImGui Example", nullptr, nullptr);
    glfwSetWindowPos(window, 500, 100);
    if (!window) {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Your ImGui code here
        // ImGui::SetNextWindowPos(ImVec2(0, 0));
        bool p_open = true; // добавляется крестик.
        ImGui::Begin("Hello, world!", &p_open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar);
        int x, y;
        glfwGetWindowPos(window, &x, &y);
        ImVec2 offset = ImGui::GetWindowPos();
        ImGui::Text("Offset: %f, %f\nWindow: %i, %i", offset.x, offset.y, x, y);
        ImGui::Button("Test Button");

        ImVec2 displaySize = ImGui::GetIO().DisplaySize;
        ImVec2 newSize = ImGui::GetWindowSize();
        glfwSetWindowShouldClose(window, p_open ? GL_FALSE : GL_TRUE);
        if (displaySize.x != newSize.x || displaySize.y != newSize.y)
            glfwSetWindowSize(window, newSize.x, newSize.y);
        // вот человек как сделал перетаскивание окна: https://github.com/ocornut/imgui/issues/4389#issuecomment-892155678

        // if (ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
        //     ReleaseCapture();
        //     SendMessageW(hwnd, 0xA1, 0x2, 0);
        // }
        
        glfwSetWindowPos(window, x + (int)offset.x, y + (int)offset.y);
        if (offset.x != 0 || offset.y != 0) 
        {
            ImGui::Text("Оно меняетчс");
            // glfwSetWindowPos(window, x + (int)offset.x, y + (int)offset.y);
            // ImGui::SetWindowPos(ImVec2(0, 0));
        }

        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.05f, 0.05f, 0.05f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}