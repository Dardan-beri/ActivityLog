#include "gtest/gtest.h"
#include "../ActivityLog.h"

// Test sulle operazioni base della struct time
TEST(ActivityTest, TimeStructOperations) {
    struct time t1;
    t1.hour = 8; t1.minute = 30; t1.second = 0;

    struct time t2;
    t2.hour = 8; t2.minute = 30; t2.second = 0;

    struct time t3;
    t3.hour = 9; t3.minute = 0; t3.second = 0;

    // Verifica operatore di uguaglianza tra due orari uguali
    EXPECT_TRUE(t1 == t2);

    // Verifica che due orari diversi non siano uguali
    EXPECT_FALSE(t1 == t3);

    // Verifica operatore di confronto (minore) tra orari
    EXPECT_TRUE(t1 < t3);
    EXPECT_FALSE(t3 < t1);

    // Verifica che il metodo toString restituisca il formato corretto
    struct time t4;
    t4.hour = 12; t4.minute = 5; t4.second = 9;
    EXPECT_EQ(t4.toString(), "12:05:09");
}

// Test sulle operazioni base della struct activity
TEST(ActivityTest, ActivityStructOperations) {
    struct activity a1;
    a1.description = "Desc1";
    a1.title = "Title1";
    a1.start = {8, 0, 0};
    a1.end = {9, 0, 0};

    struct activity a2;
    a2.description = "Desc2";
    a2.title = "Title2";
    a2.start = {9, 0, 0};
    a2.end = {10, 0, 0};

    // Verifica uguaglianza con sé stesso
    EXPECT_TRUE(a1 == a1);

    // Verifica disuguaglianza tra due attività diverse (per titolo)
    EXPECT_FALSE(a1 == a2);

    // Verifica ordinamento tra due attività in base all'orario di inizio
    EXPECT_TRUE(a1 < a2);

    // Verifica correttezza del metodo toString()
    std::string expected = "Title: Title1\nDescription: Desc1\nStart: 08:00:00\nEnd: 09:00:00\n";
    EXPECT_EQ(a1.toString(), expected);
}

// Test per aggiunta e cancellazione di attività nel log
TEST(ActivityLogTest, AddAndDeleteActivities) {
    ActivityLog log;

    // Creazione attività di test
    struct activity test_activity;
    test_activity.title = "Test";
    test_activity.description = "Description";
    test_activity.start = {10, 0, 0};
    test_activity.end = {11, 0, 0};

    // Verifica aggiunta attività
    EXPECT_TRUE(log.addActivity(test_activity));
    EXPECT_EQ(log.getActivities().size(), 1);

    // Verifica cancellazione tramite oggetto
    EXPECT_TRUE(log.deleteActivity(test_activity));
    EXPECT_TRUE(log.getActivities().empty());

    // Verifica cancellazione tramite titolo
    log.addActivity(test_activity);
    std::string title = "Test";
    EXPECT_TRUE(log.deleteActivity(title));
    EXPECT_TRUE(log.getActivities().empty());
}

// Test per l'accesso agli elementi tramite operatore []
TEST(ActivityLogTest, AccessOperator) {
    ActivityLog log;

    // Due attività da inserire
    struct activity a1;
    a1.title = "First";
    a1.start = {8, 0, 0};

    struct activity a2;
    a2.title = "Second";
    a2.start = {9, 0, 0};

    log.addActivity(a1);
    log.addActivity(a2);

    // Verifica accesso agli elementi per posizione
    EXPECT_EQ(log[0].title, "First");
    EXPECT_EQ(log[1].title, "Second");

    // Verifica ordinamento delle attività in base all'orario di inizio
    EXPECT_TRUE(log[0].start < log[1].start);
}
