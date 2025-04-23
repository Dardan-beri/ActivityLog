#include "gtest/gtest.h"
#include "../ActivityLog.h"

// Verifica l'uguaglianza tra un'attività e una stringa (titolo)
TEST(ActivityTest, EqualityWithString) {
    activity a;
    a.title = "Read";
    EXPECT_TRUE(a == "Read");
    EXPECT_FALSE(a == "Sleep");
}

// Verifica che due attività con lo stesso titolo siano considerate uguali
TEST(ActivityTest, ActivitiesWithSameTitleAreEqual) {
    activity a1, a2;
    a1.title = "Meeting";
    a2.title = "Meeting";
    EXPECT_TRUE(a1 == a2);
}

// Verifica comportamento toString con dati vuoti
TEST(ActivityTest, ActivityToStringEdgeCase) {
    activity a;
    a.title = "";
    a.description = "";
    a.start = {0, 0, 0};
    a.end = {0, 0, 0};

    std::string expected = "Title: \nDescription: \nStart: 00:00:00\nEnd: 00:00:00\n";
    EXPECT_EQ(a.toString(), expected);
}
