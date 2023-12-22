void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Generate random data for each of the 13 cells
  float cellVoltages[13];
  float totalVoltage = 0;
  float batteryCapacity = 0; // Assumed capacity in Ah, needs to be defined based on your battery
  float dischargeVoltage = 0; // Assumed discharge voltage, needs to be defined based on your specifications

  for(int i = 0; i < 13; i++) {
    cellVoltages[i] = random(200, 250) / 10.0;  // Random voltage for each cell between 20.0 and 25.0
    totalVoltage += cellVoltages[i]; // Summing up the total voltage
  }

  float current = random(10, 30) / 10.0;    // Random current between 1.0 and 3.0
  float temperature = random(25, 40);       // Random temperature between 25 and 40

  // Print the data for each cell
  for(int i = 0; i < 13; i++) {
    Serial.print("Cell ");
    Serial.print(i+1);
    Serial.print(" Voltage: ");
    Serial.print(cellVoltages[i], 1);
    Serial.print(" V, Temperature: ");
    Serial.print(temperature); // Assuming same temperature for all cells
    Serial.println(" °C");
  }

  // Print total voltage, battery capacity, and discharge voltage
  Serial.print("Total Voltage: ");
  Serial.print(totalVoltage, 1);
  Serial.println(" V");
  Serial.print("Battery Capacity: ");
  Serial.print(batteryCapacity);
  Serial.println(" Ah");
  Serial.print("Discharge Voltage: ");
  Serial.print(dischargeVoltage);
  Serial.println(" V");

  delay(5000); // Wait for 5 seconds before generating the next set of data
}
