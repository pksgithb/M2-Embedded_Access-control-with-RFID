# TEST PLAN:

## Table name: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P**      | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------ |-------------     |----------------|------------------|
|  H_01       |Code run                                         | Code run        |Code run   |00:00 |Requirement based |
|  H_02       |Hours                                       |    Press B1        |Set Hours |Set Hours |Scenario based    |
|  H_03       |Minutes                                             | Press B2           |Set Minutes |Set Minutes  |Requirement based    |

## Table name: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       |To visible seconds                                         |Calculate Hours            |Seconds shown |12:30:55 |Scenario based    |
|  L_02       |Reset                                                          | Press B3          |Shows new time |Adds time & EXIT|Boundary based    |

