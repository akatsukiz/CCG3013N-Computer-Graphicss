#include "object.cpp"

// Additional object for debvugging
Object debug = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

#pragma region Group Backdrop
Object backdrop = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderBackdrop()
{
    // Backdrop abstracts
    glColor4f(COLOR_GREEN_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.5, 100, -40, 158);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.1, 40, 170, 290);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 3.5, 800, 0, 360);

    glColor4f(COLOR_RED_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.8, 150, 200, 45);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.4, 80, 50, 140);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 2.1, 20, 0, 360);
    glColor4f(COLOR_GREEN_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.7, 80, 245, 0);

    glColor4f(COLOR_ORANGE_1);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.9, 120, 25, 105);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 1.3, 120, 200, 260);
    backdrop.drawTorus(WATCH_BODY_RADIUS * 2.4, 75, 145, 290);

    // Add Watch Glow from the body
    glColor4f(COLOR_WHITE_1);
    for (int i = WATCH_BODY_RADIUS; i <= WATCH_BODY_RADIUS + 200; i += 40)
        backdrop.drawCircle(i, 0, 360);
}
#pragma endregion Group Backdrop

#pragma region Group Watch Body
Object watchBody = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watchStrap = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watchButton = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderWatchBody()
{
    // Watch Button 1
    glColor4f(COLOR_GREY);
    watchButton.drawCircle(WATCH_BODY_RADIUS + 30, 50, 80);
    glColor4f(COLOR_RED_DARK);
    watchButton.drawCircle(WATCH_BODY_RADIUS + 20, 50, 80);

    // Watch button 2
    glColor4f(COLOR_GREY);
    watchButton.drawCircle(WATCH_BODY_RADIUS + 30, 110, 140);

    // Watch Body
    glColor4f(COLOR_WHITE);
    watchBody.drawCircle(WATCH_BODY_RADIUS, 0, 360);

    glColor4f(COLOR_BLACK_2);
    for (int i = WATCH_BODY_RADIUS; i >= BACKGROUND_CIRCLE_RADIUS; i--)
    {
        watchBody.drawCircle(i, 0, 360);
        watchBody.drawCircle(i, 0, 360);
    }
    glColor4f(COLOR_BLACK);
    watchBody.drawTorus(BACKGROUND_CIRCLE_RADIUS, 25, 0, 360); // Base layer for the watch body inner circle
    watchBody.drawTorus(WATCH_BODY_RADIUS, 20, 0, 360);        // Over layer for the watch body outline

    // Add body highlight
    glColor4f(COLOR_WHITE_3);
    watchBody.drawTorus(WATCH_BODY_RADIUS, 8, 0, 360);
    watchBody.drawTorus(WATCH_BODY_RADIUS + 3, 3, 0, 360);
    glColor4f(COLOR_WHITE);
    watchBody.drawTorus(WATCH_BODY_RADIUS + 3, 2, 90, 180);
    watchBody.drawTorus(WATCH_BODY_RADIUS + 3, 2, 280, 340);
}

void renderWatchStrap()
{
    // Watch Strap
    glColor4f(COLOR_GREEN_DARK);
    watchStrap.drawRoundedRectFill(BACKGROUND_CIRCLE_RADIUS + 20, WINDOWS_HEIGHT, 0);
    glColor4f(COLOR_GREEN);
    watchStrap.drawRoundedRectFill(BACKGROUND_CIRCLE_RADIUS, WINDOWS_HEIGHT, 0);
    glColor4f(COLOR_GREEN_DARK_1);
    for (int i = BACKGROUND_CIRCLE_RADIUS; i >= BACKGROUND_CIRCLE_RADIUS - 150; i -= 15)
        watchStrap.drawRoundedRectFill(i, WINDOWS_HEIGHT, 0);

    // Center Red
    glColor4f(COLOR_RED_DARK);
    watchStrap.translate(50, 0);
    watchStrap.drawRoundedRectFill(BACKGROUND_CIRCLE_RADIUS / 2, WINDOWS_HEIGHT, 0);

    glColor4f(COLOR_RED_1);
    for (int i = BACKGROUND_CIRCLE_RADIUS / 2; i > (BACKGROUND_CIRCLE_RADIUS / 2) - 100; i -= 10)
        watchStrap.drawRoundedRectFill(i, WINDOWS_HEIGHT, 0);

    // Side left
    glColor4f(COLOR_RED);
    watchStrap.translate(-170, 0);
    watchStrap.drawRoundedRectFill(15, WINDOWS_HEIGHT, 0);

    glColor4f(COLOR_WHITE);
    watchStrap.translate(-50, 0);
    watchStrap.drawRoundedRectFill(15, WINDOWS_HEIGHT, 0);

    // Side Right
    watchStrap.translate(280, 0);
    glColor4f(COLOR_ORANGE_1);
    for (int i = 15; i > 5; i--)
        watchStrap.drawRoundedRectFill(i, WINDOWS_HEIGHT, 0);
    glColor4f(COLOR_ORANGE_1);
    for (int i = 5; i >= 0; i--)
        watchStrap.drawRoundedRectFill(i, WINDOWS_HEIGHT, 0);

    // Holes
    watchStrap.x = WINDOWS_CENTER_X;                           // Reset x
    watchStrap.y = WINDOWS_CENTER_Y + WINDOWS_HEIGHT / 2 - 50; // Reset y
    glColor4f(COLOR_BLACK);
    for (int i = 0; i < 2; i++)
    {
        watchStrap.drawRoundedRectFill(STRAP_HOLE_WIDTH, STRAP_HOLE_HEIGHT, STRAP_HOLE_CORNER_RADIUS);
        watchStrap.translate(0, -150);
    }
}
#pragma endregion Group Watch Body

#pragma region Group Background
Object background = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object seconds = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object outerRing = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

Object watermelonShellA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonShellB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonFleshA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonFleshB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonSeedA = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object watermelonSeedB = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderBackground()
{
    // Watchface Background
    glColor4f(COLOR_GREEN_LIGHT);
    background.drawCircle(BACKGROUND_CIRCLE_RADIUS, 0, 360);

    // Seconds ring
    glColor4f(COLOR_RED);
    seconds.drawTorus(SECONDS_RING_RADIUS, SECONDS_RING_THICKNESS, 0, 194);

    // Decorative green outer ring
    glColor4f(COLOR_GREEN);
    outerRing.drawTorus(OUTER_RING_RADIUS, OUTER_RING_THICKNESS, 0, 360);

    glColor4f(COLOR_WHITE_1);
    for (int i = OUTER_RING_RADIUS; i >= OUTER_RING_RADIUS - (OUTER_RING_THICKNESS / 2); i--)
    {
        for (int j = 1; j <= (OUTER_RING_RADIUS - i + 1); j++)
        {
            outerRing.drawTorus(i, 1, 0, 360); // Adds a gradient effect to the outer ring
        }
    }
}

void renderWatermelon()
{
    // Watermelon Shell
    // Define the watermelon shell
    const int shellThicknessA = 15;
    const int shellThicknessB = 40;
    // Define the watermelon A flesh
    const int watermelonARadius = 140;
    const int watermelonAOffsetX = -150;
    const int watermelonAOffsetY = -150;
    const int watermelonARotation = 50;
    const int watermelonASeedOffsetX = -180;
    const int watermelonASeedOffsetY = -180;
    const int watermelonBRadius = 450;
    const int watermelonBOffsetX = 10;
    const int watermelonBOffsetY = 350;
    const int watermelonBRotation = -10;
    const int watermelonBSeedOffsetX = -180;
    const int watermelonBSeedOffsetY = -180;
    // Define the watermelon seeds
    const int watermelonSeedABottomRadius = 5;
    const int watermelonSeedATopRadius = 2;
    const int watermelonSeedALength = 9;
    const int watermelonSeedBBottomRadius = 8;
    const int watermelonSeedBTopRadius = 3;
    const int watermelonSeedBLength = 16;

    // Watermelon Shell
    glColor4f(COLOR_GREEN_1); // Set color to transparently green
    watermelonShellA.translate(watermelonAOffsetX, watermelonAOffsetY);
    watermelonShellA.drawTorus(watermelonARadius, shellThicknessA, 90 + watermelonARotation, 270 + watermelonARotation);

    watermelonShellB.translate(watermelonBOffsetX, watermelonBOffsetY);
    watermelonShellB.drawTorus(watermelonBRadius, shellThicknessB, 130 + watermelonBRotation, 200 + watermelonBRotation);

    // Watermelon Flesh
    glColor4f(COLOR_RED_1);
    watermelonFleshA.translate(watermelonAOffsetX, watermelonAOffsetY);
    watermelonFleshA.drawCircle(watermelonARadius - shellThicknessA, 90 + watermelonARotation, 270 + watermelonARotation);

    watermelonFleshB.translate(watermelonBOffsetX, watermelonBOffsetY);
    watermelonFleshB.drawCircle(watermelonBRadius - shellThicknessB, 130 + watermelonBRotation, 200 + watermelonBRotation);

    // Watermelon Seed
    glColor4f(COLOR_BLACK_2);
    watermelonSeedA.translate(watermelonAOffsetX, watermelonAOffsetY);
    watermelonSeedA.translate(-30, -26);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 45);
    watermelonSeedA.translate(82, -54);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, -18);
    watermelonSeedA.translate(-40, -34);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 15);
    watermelonSeedA.translate(-28, 40);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 35);
    watermelonSeedA.translate(-40, -12);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 28);
    watermelonSeedA.translate(-38, 42);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 58);
    watermelonSeedA.translate(20, 49);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 78);
    watermelonSeedA.translate(-10, 40);
    watermelonSeedA.drawTautBelt(watermelonSeedABottomRadius, watermelonSeedATopRadius, watermelonSeedALength, 95);

    watermelonSeedB.translate(watermelonBOffsetX, watermelonBOffsetY);
    watermelonSeedB.translate(26, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -30);
    watermelonSeedB.translate(62, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -59);
    watermelonSeedB.translate(-80, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, 12);
    watermelonSeedB.translate(66, -26);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -23);
    watermelonSeedB.translate(106, -13);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -44);
    watermelonSeedB.translate(-53, -48);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -14);
    watermelonSeedB.translate(145, -4);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -74);
    watermelonSeedB.translate(-56, -40);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -54);
    watermelonSeedB.translate(-30, -63);
    watermelonSeedB.drawTautBelt(watermelonSeedBBottomRadius, watermelonSeedBTopRadius, watermelonSeedBLength, -34);
}
#pragma endregion Group Background

#pragma region Group Center Piece
Object coreCircle = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object minutes = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object analogQuaterIndicator = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object analogIndicator = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textAMPM = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textMinute = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderCenterPiece()
{
    // Core red circle
    glColor4f(COLOR_RED);
    coreCircle.drawCircle(CORE_CIRCLE_RADIUS, 0, 360);
    glColor4f(COLOR_YELLOW_1);
    for (int i = 90; i >= 50; i -= 10)
        coreCircle.drawCircle(CORE_CIRCLE_RADIUS - i, 0, 360);
    glColor4f(COLOR_ORANGE_1);
    for (int i = 40; i >= 10; i -= 10)
        coreCircle.drawCircle(CORE_CIRCLE_RADIUS - i, 0, 360);

    // Minutes circle
    glColor4f(COLOR_GREEN_DARK);
    minutes.drawCircle(MINUTES_CIRCLE_RADIUS, 0, 288);
    glColor4f(COLOR_GREEN_1);
    for (int i = 10; i <= 70; i += 10)
        minutes.drawCircle(MINUTES_CIRCLE_RADIUS - i, 0, 288);
    glColor4f(COLOR_WHITE_1);
    for (int i = 13; i >= 6; i--)
        minutes.drawTorus(MINUTES_CIRCLE_RADIUS - 20, i, 0, 288);

    // -- Analog Indicator
    glColor4f(COLOR_WHITE);
    // Draw the quater indicator
    for (int i = 90; i <= 360; i += 90)
    {
        analogQuaterIndicator.drawTorus(
            MINUTES_CIRCLE_RADIUS - ANALOG_QUATER_INDICATOR_LENGTH / 2,
            ANALOG_QUATER_INDICATOR_LENGTH,
            i - ANALOG_INDICATOR_WIDTH,
            i + ANALOG_INDICATOR_WIDTH);
    }
    // Draw the minute indicator non quater
    for (int i = 30; i <= 330; i += 30)
    {
        if (i == 90 || i == 180 || i == 270 || i == 360)
        {
            continue;
        }
        analogIndicator.drawTorus(
            CORE_CIRCLE_RADIUS - ANALOG_INDICATOR_LENGTH / 2,
            ANALOG_INDICATOR_LENGTH,
            i - ANALOG_INDICATOR_WIDTH,
            i + ANALOG_INDICATOR_WIDTH);
    }

    // Minute text
    textMinute.translate(-105, -45);
    glColor4f(COLOR_GREEN_DARK);
    textMinute.drawText("48", 10);
    glColor4f(COLOR_WHITE);
    textMinute.drawText("48", 8);

    // AM PM text
    textAMPM.translate(-30, -100);
    textAMPM.scale(0.30);
    glColor4f(COLOR_GREEN_DARK);
    textAMPM.drawText("AM", 5);
    textAMPM.scale(0.30);
    glColor4f(COLOR_WHITE);
    textAMPM.drawText("AM", 3);
}
#pragma endregion Group Center Piece

#pragma region Group Hour
Object hourCircle = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object hourPointer = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textHour = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderHour()
{
    int current_Hour = 8;

    // Hour pointer
    glColor4f(COLOR_ORANGE);
    hourPointer.drawTorus(OUTER_RING_RADIUS * .90, 15, 240, 264);

    // Hour circle
    hourCircle.translate(0, OUTER_RING_RADIUS * .90);
    for (int i = 0; i <= 360; i += 30)
    {

        hourCircle.rotate(i, WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
        if (i == current_Hour * 30)
        {
            glColor4f(COLOR_RED);
            hourCircle.drawCircle(60, 0, 360);
            // glColor4f(COLOR_ORANGE_1);
            // for (int j = 0; j <= 20; j+=5)
            // {
            //     hourCircle.rotate(i, WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
            //     hourCircle.drawCircle(60 - j, 0, 360);
            // }
            // glColor4f(COLOR_YELLOW_1);
            // for (int j = 0; j <= 20; j += 5)
            // {
            //     hourCircle.rotate(i, WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
            //     hourCircle.drawCircle(40 - j, 0, 360);
            // }
        }
        else
        {
            glColor4f(COLOR_BLACK);
            hourCircle.drawCircle(5, 0, 360);
        }
    }

    // Hour text
    glColor4f(COLOR_RED_DARK);
    textHour.translate(-401, -239);
    textHour.scale(0.50);
    textHour.drawText("8", 10);
    glColor4f(COLOR_WHITE);
    textHour.scale(0.50);
    textHour.drawText("8", 7);
}
#pragma endregion Group Hour

#pragma region Group == == == == Complication

#pragma region Group Date and Day
Object dayBox = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object dateBox = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textDate = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textDay = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderDateDay()
{
    // Draw day box
    glColor4f(COLOR_RED);
    dayBox.translate(COMPLICATION_RING_RADIUS, -20);
    dayBox.drawRoundedRectFill(DAY_BOX_WIDTH, DAY_BOX_HEIGHT, DAY_BOX_CORNER_RADIUS);

    // Draw date box
    glColor4f(COLOR_GREEN_DARK);
    dateBox.translate(COMPLICATION_RING_RADIUS, 20);
    dateBox.drawRoundedRectFill(DATE_BOX_WIDTH + 10, DATE_BOX_HEIGHT + 10, DATE_BOX_CORNER_RADIUS + 5);
    glColor4f(COLOR_GREEN);
    dateBox.drawRoundedRectFill(DATE_BOX_WIDTH, DATE_BOX_HEIGHT, DATE_BOX_CORNER_RADIUS);

    // Draw date text
    glColor4f(COLOR_WHITE);
    textDate.translate(COMPLICATION_RING_RADIUS - 80, 10);
    textDate.scale(0.25);
    textDate.drawText("12|Feb", 4);

    // Draw day text
    glColor4f(COLOR_WHITE);
    textDay.translate(COMPLICATION_RING_RADIUS - 25, -40);
    textDay.scale(0.15);
    textDay.drawText("Thu", 3);
}
#pragma endregion Group Date and Day

#pragma region Group Heart
Object iconHeart = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textHeartRate = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderHeart()
{
    // The heart rate icon
    glColor4f(COLOR_RED);
    iconHeart.translate(-90, COMPLICATION_RING_RADIUS);
    iconHeart.drawHeart(20);

    // Heart rate text
    textHeartRate.translate(-50, COMPLICATION_RING_RADIUS - 10);
    glColor4f(COLOR_WHITE);
    textHeartRate.scale(0.25);
    textHeartRate.drawText("76bpm", 8);
    glColor4f(COLOR_GREY);
    textHeartRate.scale(0.25);
    textHeartRate.drawText("76bpm", 5);
}
#pragma endregion Group Heart

#pragma region Group Battery
Object iconBattery = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textBattery = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderBattery()
{
    // Battery text
    textBattery.translate(-10, -COMPLICATION_RING_RADIUS - 15);
    glColor4f(COLOR_GREY);
    textBattery.scale(0.25);
    textBattery.drawText("60%", 8);
    glColor4f(COLOR_RED);
    textBattery.scale(0.25);
    textBattery.drawText("60%", 4);

    // Battery icon
    glColor4f(COLOR_BLACK);
    iconBattery.translate(-35, -COMPLICATION_RING_RADIUS);
    iconBattery.drawBattery(20, 2, 1, 60);
}
#pragma endregion Group Battery

#pragma region Group Step
Object textStepCount = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
Object textStepUnit = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);

void renderStep()
{
    // Step count text
    textStepCount.translate(-COMPLICATION_RING_RADIUS - 50, 0);
    glColor4f(COLOR_WHITE);
    textStepCount.scale(0.35);
    textStepCount.drawText("4896", 8);
    glColor4f(COLOR_GREY);
    textStepCount.scale(0.35);
    textStepCount.drawText("4896", 5);

    // Step unit text
    glColor4f(COLOR_GREY);
    textStepUnit.translate(-COMPLICATION_RING_RADIUS - 4, -28);
    textStepUnit.scale(0.15);
    textStepUnit.drawText("Step", 8);
    glColor4f(COLOR_RED);
    textStepUnit.scale(0.15);
    textStepUnit.drawText("Step", 4);
}
#pragma endregion Group Step

// Master function to render the complication
void renderComplication()
{
    renderDateDay();
    renderHeart();
    renderBattery();
    renderStep();
}
#pragma endregion Group == == == == Complication

#pragma region Group Watch Glass
Object watchGlass = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderWatchGlass()
{
    // Watch glass
    glColor4f(COLOR_BLACK_1);
    watchGlass.drawCircle(BACKGROUND_CIRCLE_RADIUS, 0, 360);

    // Watch glass vignette
    int lowerBound = BACKGROUND_CIRCLE_RADIUS - 120;
    int upperBound = BACKGROUND_CIRCLE_RADIUS;
    int step = upperBound - lowerBound;
    for (int i = upperBound; i >= lowerBound; i--)
    {
        for (int j = lowerBound; j <= i; j++)
            watchGlass.drawTorus(i, 1, 0, 360);
    }

    // Reflect element on glass
    glColor4f(COLOR_WHITE_2);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 65, 85, 90, 160);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 95, 45, 100, 180);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 65, 60, 290, 338);
    watchGlass.drawTorus(BACKGROUND_CIRCLE_RADIUS - 70, 25, 300, 350);
}
#pragma endregion Group Watch Glass

#pragma region Group Vignnette Filter
Object vignetteFilter = Object(WINDOWS_CENTER_X, WINDOWS_CENTER_Y);
void renderVignetteFilter()
{
    // Vignette Filter
    glColor4f(COLOR_BLACK_VIG);
    int initialRadius = WINDOWS_WIDTH;
    int initialWidth = 1600;
    vignetteFilter.drawTorus(initialRadius, initialWidth, 0, 360);
    for (int i = 0; i <= 220; i++)
    {
        vignetteFilter.drawTorus(initialRadius, initialWidth, 0, 360);
        initialWidth -= 30;
    }
}
#pragma endregion Group Vignnette Filter
