// Include rendering functions
#include "render.h"

void renderMaster()
{
    // Render code here.
    renderBackdrop();       // Backdrop
    renderWatchStrap();      // Watch Strap
    renderVignetteFilter(); // Vignette Filter

    renderWatchBody();  // Watch Body
    renderBackground(); // Seconds and Outer Ring
    renderWatermelon(); // Watermelon, background wallpaper

    renderCenterPiece();  // Minutes and Analog Indicator
    renderHour();         // Hour
    renderComplication(); // Complication (Date, Day, Heart, Battery, Step)

    renderWatchGlass(); // Watch Glass

    // For debugging purpose
    // glColor4f(COLOR_BLACK);
    // debug.drawCircle(5, 0, 360);

    glFlush();  // Clear all GL executions.
    glFinish(); // Block until all GL executions are completed.
}

void init()
{
    // Initialize the windows
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);                   // Set the display mode to single buffer and RGBA.
    glutInitWindowSize(WINDOWS_WIDTH, WINDOWS_HEIGHT);              // Set the windows size.
    glutInitWindowPosition(WINDOWS_CENTER_Y, WINDOWS_CENTER_Y);     // Set the windows position.
    glutCreateWindow("Watermelon-ish Watch Face v1.0 by @cheahPC"); // Set the windows title.
    glutFullScreen();                                               // Set the windows to full screen.

    // Initialize the rendering context
    glClearColor(COLOR_GREEN_LIGHT);                   // Set the background color to white, any area not rendered will be white.
    glMatrixMode(GL_PROJECTION);                       // Set the matrix mode to projection.
    glEnable(GL_LINE_SMOOTH);                          // Enables line anti-aliasing.
    glEnable(GL_BLEND);                                // Enable for proper transparency render.
    glDisable(GL_DEPTH_TEST);                          // Disable depth testing for overlap object. Use for transparency object involved.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Enable transparency.
    Object::glEndReset();                              // Reset the matrix.
    glClear(GL_COLOR_BUFFER_BIT);                      // Load frame buffer.
}
