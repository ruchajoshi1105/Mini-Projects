<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>MandiMate | Smart Agriculture</title>

<style>
/* Define common colors used throughout the website */
:root {
  --green: #176b45;
  --dark: #103d2b;
  --light: #edf8f0;
  --text: #18352b;
  --muted: #65776e;
  --border: #dce9df;
}

/* Apply box-sizing to all elements */
* {
  box-sizing: border-box;
}

/* Style the main body of the website */
body {
  margin: 0;
  font-family: "Segoe UI", Arial, sans-serif;
  background: #f5f9f6;
  color: var(--text);
}

/* Style the header section */
header {
  background: linear-gradient(120deg, #103d2b, #19704a);
  color: white;
  padding: 23px 6%;
  display: flex;
  justify-content: space-between;
  align-items: center;
  gap: 15px;
  flex-wrap: wrap;
}

/* Arrange the logo and brand information */
.brand {
  display: flex;
  align-items: center;
  gap: 12px;
}

/* Set the logo size */
.logo {
  font-size: 43px;
}

/* Style the website title */
.brand h1 {
  margin: 0;
  font-size: 29px;
}

/* Highlight the Mate part of the title */
.brand h1 span {
  color: #a9e6a9;
}

/* Style the brand description */
.brand p {
  margin: 5px 0 0;
  color: #d4e7d9;
  font-size: 13px;
}

/* Arrange navigation links horizontally */
nav {
  display: flex;
  gap: 20px;
}

/* Style navigation links */
nav a {
  color: white;
  text-decoration: none;
  font-size: 14px;
}

/* Style the hero section */
.hero {
  background: linear-gradient(115deg, #e7f6e9, #ffffff 65%, #d9f0dc);
  padding: 38px 6% 32px;
}

/* Style the main heading */
.hero h2 {
  font-size: clamp(25px, 4vw, 36px);
  margin: 0 0 10px;
  color: var(--dark);
}

/* Style the hero description */
.hero p {
  color: var(--muted);
  margin: 0;
  line-height: 1.7;
}

/* Set the main content width and spacing */
main {
  max-width: 1450px;
  margin: auto;
  padding: 25px 5%;
}

/* Create reusable card designs */
.card {
  background: white;
  border: 1px solid var(--border);
  border-radius: 15px;
  padding: 23px;
  margin-bottom: 22px;
  box-shadow: 0 4px 15px #143c2010;
}

/* Style card headings */
.card h3 {
  margin: 0 0 19px;
  font-size: 19px;
}

/* Arrange form fields in three columns */
.form-grid {
  display: grid;
  grid-template-columns: repeat(3, 1fr);
  gap: 18px;
}

/* Style form labels */
label {
  display: block;
  font-size: 13px;
  font-weight: 600;
  margin-bottom: 8px;
}

/* Style input fields and dropdown menus */
input, select {
  width: 100%;
  padding: 13px;
  background: white;
  border: 1px solid #cbdcd0;
  border-radius: 9px;
  font-size: 15px;
  color: var(--text);
}

/* Highlight fields when selected */
input:focus, select:focus {
  outline: 2px solid #9dd6ad;
  border-color: var(--green);
}

/* Style all buttons */
button {
  border: 0;
  background: var(--green);
  color: white;
  font-weight: 600;
  font-size: 15px;
  padding: 14px 20px;
  border-radius: 9px;
  cursor: pointer;
  transition: 0.2s;
}

/* Add a hover effect to buttons */
button:hover {
  background: #0f5032;
  transform: translateY(-1px);
}

/* Make the search button occupy the full width */
.search-button {
  margin-top: 20px;
  width: 100%;
}

/* Arrange the summary statistics in four columns */
.stats {
  display: grid;
  grid-template-columns: repeat(4, 1fr);
  gap: 15px;
  margin-bottom: 22px;
}

/* Style individual statistics cards */
.stat {
  padding: 20px;
  border-radius: 13px;
  border: 1px solid var(--border);
  background: white;
}

/* Style statistic labels */
.stat small {
  color: var(--muted);
  font-size: 12px;
}

/* Style statistic values */
.stat h3 {
  font-size: 23px;
  margin: 12px 0 6px;
  overflow-wrap: anywhere;
}

/* Style statistic descriptions */
.stat p {
  margin: 0;
  color: var(--muted);
  font-size: 12px;
}

/* Apply different background colors to statistics cards */
.stat.green { background: #eaf7ed; }
.stat.blue { background: #edf5ff; }
.stat.orange { background: #fff4e9; }
.stat.purple { background: #f5efff; }

/* Arrange the market table and chart */
.results-grid {
  display: grid;
  grid-template-columns: 1.25fr 1fr;
  gap: 20px;
  align-items: start;
}

/* Allow horizontal scrolling for wide tables */
.table-wrap {
  overflow-x: auto;
}

/* Style the market comparison table */
table {
  width: 100%;
  border-collapse: collapse;
  font-size: 13px;
  white-space: nowrap;
}

/* Style table cells */
th, td {
  text-align: left;
  padding: 13px 10px;
  border-bottom: 1px solid #e7eee8;
}

/* Highlight table headings */
th {
  background: #f0f7f1;
  font-size: 12px;
}

/* Highlight the best-performing mandi row */
tr.best {
  background: #e7f7ec;
  font-weight: 600;
}

/* Create a badge for the best mandi */
.pill {
  display: inline-block;
  padding: 4px 8px;
  margin-left: 5px;
  border-radius: 20px;
  background: #d2f0d9;
  color: #176b45;
  font-size: 10px;
}

/* Arrange chart bars vertically */
.chart {
  display: flex;
  flex-direction: column;
  gap: 16px;
}

/* Arrange each chart row */
.bar-row {
  display: grid;
  grid-template-columns: 95px 1fr 90px;
  gap: 9px;
  align-items: center;
  font-size: 12px;
}

/* Style the background track of each bar */
.bar-track {
  height: 22px;
  background: #edf2ee;
  border-radius: 5px;
  overflow: hidden;
}

/* Style the chart bars */
.bar {
  height: 100%;
  background: linear-gradient(90deg, #249568, #69c68a);
  border-radius: 5px;
  transition: width 0.4s;
}

/* Use a different color for the best mandi bar */
.bar-row.best-bar .bar {
  background: linear-gradient(90deg, #df9a28, #f6c75e);
}

/* Align the net return values to the right */
.bar-value {
  text-align: right;
  font-weight: 600;
}

/* Style the dispatch recommendation section */
.recommendation {
  background: linear-gradient(120deg, #e7f7eb, #ffffff);
  border: 1px solid #bfe4ca;
  border-radius: 15px;
  padding: 25px;
  margin-top: 22px;
}

/* Style the recommendation heading */
.recommendation h3 {
  margin-top: 0;
  color: var(--green);
}

/* Add spacing below the recommendation title */
.recommendation h2 {
  margin-bottom: 8px;
}

/* Style recommendation descriptions */
.recommendation p {
  color: #52675a;
  line-height: 1.7;
}

/* Highlight important recommendation text */
.recommendation strong {
  color: var(--dark);
}

/* Style informational notes */
.note {
  font-size: 12px;
  color: var(--muted);
  line-height: 1.6;
  margin: 18px 0;
}

/* Style the website footer */
footer {
  text-align: center;
  padding: 22px;
  background: var(--dark);
  color: #d8e8dc;
  font-size: 13px;
}

/* Adjust the layout for tablets and medium screens */
@media (max-width: 900px) {
  .stats {
    grid-template-columns: repeat(2, 1fr);
  }

  .results-grid {
    grid-template-columns: 1fr;
  }
}

/* Adjust the layout for mobile screens */
@media (max-width: 600px) {
  header {
    padding: 18px 5%;
  }

  .brand h1 {
    font-size: 24px;
  }

  nav {
    width: 100%;
    gap: 18px;
  }

  .hero {
    padding: 28px 5%;
  }

  main {
    padding: 18px 4%;
  }

  /* Display form fields in a single column */
  .form-grid {
    grid-template-columns: 1fr;
  }

  .stats {
    gap: 10px;
  }

  .stat {
    padding: 14px;
  }

  .stat h3 {
    font-size: 19px;
  }

  .card {
    padding: 16px;
  }

  /* Reduce chart column sizes for mobile screens */
  .bar-row {
    grid-template-columns: 78px 1fr 77px;
    gap: 6px;
  }
}
</style>
</head>

<body>

<!-- Header: displays the logo, project name, and navigation links -->
<header>
  <div class="brand">
    <div class="logo">🌱</div>
    <div>
      <h1>Mandi<span>Mate</span></h1>
      <p>Smart Agriculture Market Intelligence &amp; Dispatch Optimiser</p>
    </div>
  </div>

  <!-- Navigation links to different sections of the page -->
  <nav>
    <a href="#home">Home</a>
    <a href="#markets">Markets</a>
    <a href="#recommendation">Recommendation</a>
  </nav>
</header>

<!-- Hero section introduces the purpose of MandiMate -->
<section class="hero" id="home">
  <h2>Find the best mandi for your crops 🌾</h2>
  <p>
    Compare mandi prices, calculate transportation costs,
    and discover where your produce could earn more.
  </p>
</section>

<main>

  <!-- Form section: accepts crop and expense details from the user -->
  <section class="card">
    <h3>🚜 Enter Your Crop Details</h3>

    <div class="form-grid">
      <div>
        <label for="crop">Select your crop</label>

        <!-- Dropdown menu for selecting the crop -->
        <select id="crop">
          <option>Tomato</option>
          <option>Onion</option>
          <option>Potato</option>
          <option>Wheat</option>
        </select>
      </div>

      <div>
        <label for="quantity">Quantity (quintals)</label>

        <!-- Input field for crop quantity -->
        <input id="quantity" type="number"
          min="1" max="10000" value="10" step="1">
      </div>

      <div>
        <label for="otherCost">Other costs (₹ per quintal)</label>

        <!-- Input field for additional cost per quintal -->
        <input id="otherCost" type="number"
          min="0" value="100" step="10">
      </div>
    </div>

    <!-- Button starts the mandi comparison calculation -->
    <button class="search-button" onclick="calculate()">
      🔍 Find Best Mandi
    </button>

    <!-- Displays API connection and demo status messages -->
    <p id="apiStatus" class="note" role="status" aria-live="polite">
      Demo mode: sample prices are shown until a Data.gov.in API key is added.
    </p>
  </section>

  <!-- Summary section: displays revenue, expenses, and the best mandi -->
  <section class="stats">
    <div class="stat green">
      <small>💰 Best Estimated Revenue</small>
      <h3 id="revenue">₹0</h3>
      <p>Before expenses</p>
    </div>

    <div class="stat orange">
      <small>🚚 Transport Cost</small>
      <h3 id="transport">₹0</h3>
      <p>Estimated delivery cost</p>
    </div>

    <div class="stat blue">
      <small>📦 Other Costs</small>
      <h3 id="expenses">₹0</h3>
      <p>For your selected quantity</p>
    </div>

    <div class="stat purple">
      <small>🏆 Best Mandi</small>
      <h3 id="bestMandi">--</h3>
      <p>Highest estimated net return</p>
    </div>
  </section>

  <!-- Results section contains the market table and comparison chart -->
  <div class="results-grid">

    <!-- Table displays mandi prices and estimated net returns -->
    <section class="card" id="markets">
      <h3>📊 Market Comparison</h3>

      <div class="table-wrap">
        <table>
          <thead>
            <tr>
              <th>Mandi</th>
              <th>Price / Quintal</th>
              <th>Transport</th>
              <th>Other Costs</th>
              <th>Net Return</th>
            </tr>
          </thead>

          <!-- JavaScript inserts the market rows here -->
          <tbody id="marketRows"></tbody>
        </table>
      </div>
    </section>

    <!-- Chart visually compares estimated net returns -->
    <section class="card">
      <h3>📈 Net Return Comparison</h3>

      <!-- JavaScript generates the comparison bars here -->
      <div class="chart" id="chart"></div>
    </section>

  </div>

  <!-- Recommendation section displays the best mandi -->
  <section class="recommendation" id="recommendation">
    <h3>🎯 Dispatch Recommendation</h3>
    <h2 id="recommendationTitle">Calculating...</h2>
    <p id="recommendationText"></p>
    <p id="dispatchText"></p>

    <!-- Print the report using the browser's print feature -->
    <button onclick="window.print()">🖨️ Print Report</button>
  </section>

  <!-- Explain the limitations of the demonstration data -->
  <p class="note">
    ⚠️ Demo notice: The market prices and transport estimates used
    by this prototype are illustrative sample data, not live mandi
    prices. Verify actual prices and transport quotations before
    making selling or dispatch decisions. The current version
    recommends one destination; it does not yet optimise multiple
    trucks or split loads.
  </p>

</main>

<!-- Footer displays the project name and purpose -->
<footer>
  🌱 MandiMate — Helping Farmers Make Smarter Market Decisions
  <br><br>
  Built for a hackathon | Better Decisions, Better Returns
</footer>

<script>
// Official Government of India Open Government Data API.
// Get a free API key from https://www.data.gov.in/ and paste it below.
// Resource ID for daily mandi price data.
const DATA_GOV_API_KEY = "PASTE_YOUR_DATA_GOV_IN_API_KEY_HERE";
const DATA_GOV_RESOURCE = "9ef84268-d588-465a-a308-a864a43d0070";

// Sample market prices and transport estimates used in demo mode.
const sampleMarkets = [
  { name: "Pune Mandi", price: 2500, distance: 25, rate: 1.5 },
  { name: "Nashik Mandi", price: 2800, distance: 180, rate: 1.2 },
  { name: "Mumbai Mandi", price: 3000, distance: 150, rate: 1.8 },
  { name: "Satara Mandi", price: 2600, distance: 110, rate: 1.3 }
];

// Format numeric values as Indian Rupee currency.
const money = value => "₹" + Math.round(value).toLocaleString("en-IN");

// Get the API status message element.
const statusEl = () => document.getElementById("apiStatus");

// Calculate market revenue, expenses, and net returns.
function showResults(rows, crop, quantity, otherCost, isLive) {

  // Calculate total additional costs for the selected quantity.
  const otherTotal = quantity * otherCost;

  // Calculate transport costs and net returns for each market.
  const results = rows.map(row => {
    const transport = row.distance != null
      ? row.distance * row.rate * quantity
      : 150 * quantity; // Estimated transport cost when distance is unavailable.

    const revenue = row.price * quantity;

    return {
      ...row,
      revenue,
      transport,
      otherTotal,
      net: revenue - transport - otherTotal
    };

  // Sort markets from highest to lowest estimated net return.
  }).sort((a, b) => b.net - a.net);

  // Select the market with the highest estimated net return.
  const best = results[0];

  // Update the summary statistics.
  document.getElementById("revenue").textContent = money(best.revenue);
  document.getElementById("transport").textContent = money(best.transport);
  document.getElementById("expenses").textContent = money(best.otherTotal);
  document.getElementById("bestMandi").textContent = best.name;

  // Generate the market comparison table dynamically.
  document.getElementById("marketRows").innerHTML = results.map((item, index) => `
    <tr class="${index === 0 ? "best" : ""}">
      <td>${escapeHtml(item.name)}${index === 0 ? ' <span class="pill">BEST</span>' : ""}</td>
      <td>${money(item.price)}</td>
      <td>${money(item.transport)}</td>
      <td>${money(item.otherTotal)}</td>
      <td>${money(item.net)}</td>
    </tr>`).join("");

  // Find the maximum positive net return for chart scaling.
  const maxNet = Math.max(1, ...results.map(item => Math.max(0, item.net)));

  // Generate a comparison bar for every mandi.
  document.getElementById("chart").innerHTML = results.map((item, index) => {

    // Calculate each bar's width as a percentage.
    const width = Math.max(0, Math.min(100, item.net / maxNet * 100));

    return `<div class="bar-row ${index === 0 ? "best-bar" : ""}">
      <span>${escapeHtml(item.name.replace(/ Mandi$/i, ""))}</span>
      <div class="bar-track"><div class="bar" style="width:${width}%"></div></div>
      <span class="bar-value">${money(item.net)}</span>
    </div>`;

  }).join("");

  // Display the recommended mandi.
  document.getElementById("recommendationTitle").textContent = "🏆 " + best.name;

  // Explain the estimated return and whether the price data is live.
  document.getElementById("recommendationText").textContent =
    `For ${quantity.toLocaleString("en-IN")} quintals of ${crop}, the highest estimated net return is ${money(best.net)}. ` +
    (isLive
      ? "The listed crop price came from the government market-price API."
      : "This result uses illustrative sample prices, not live market data.");

  // Display a summary of revenue and estimated expenses.
  document.getElementById("dispatchText").textContent =
    `Estimated revenue: ${money(best.revenue)} | Transport estimate: ${money(best.transport)} | Other costs: ${money(best.otherTotal)}. ` +
    (best.date
      ? `Price date: ${best.date}.`
      : "Confirm today's price and transport cost before dispatch.");
}

// Escape special HTML characters before inserting market names into HTML.
function escapeHtml(value) {
  return String(value ?? "").replace(/[&<>"']/g, ch => ({
    "&": "&amp;",
    "<": "&lt;",
    ">": "&gt;",
    '"': "&quot;",
    "'": "&#39;"
  })[ch]);
}

// Fetch live crop prices from the Government of India's API.
async function fetchLivePrices(crop) {

  // Create the API request URL.
  const url = new URL(`https://api.data.gov.in/resource/${DATA_GOV_RESOURCE}`);

  // Add API key, response format, record limit, and filters.
  url.searchParams.set("api-key", DATA_GOV_API_KEY.trim());
  url.searchParams.set("format", "json");
  url.searchParams.set("limit", "100");
  url.searchParams.set("filters[state]", "Maharashtra");
  url.searchParams.set("filters[commodity]", crop);

  // Send the request to the government API.
  const response = await fetch(url.toString());

  // Handle unsuccessful API responses.
  if (!response.ok) {
    throw new Error(`Government API returned HTTP ${response.status}.`);
  }

  // Convert the API response into JSON.
  const payload = await response.json();

  // Read the returned market records.
  const records = Array.isArray(payload.records) ? payload.records : [];

  // Keep valid prices and convert records into the application's format.
  return records.filter(r => Number(r.modal_price) > 0).map(r => ({
    name: [r.market, r.district].filter(Boolean).join(" — ") || "Market not named",
    price: Number(r.modal_price),
    date: r.arrival_date || "",
    distance: null,
    rate: null
  }));
}

// Main function: validates input and calculates the best mandi.
async function calculate() {

  // Read the selected crop, quantity, and other costs.
  const crop = document.getElementById("crop").value;
  const quantity = Number(document.getElementById("quantity").value);
  const otherCost = Number(document.getElementById("otherCost").value);
  const button = document.querySelector(".search-button");

  // Validate quantity and additional costs before calculation.
  if (!Number.isFinite(quantity) || quantity < 1 || quantity > 10000 ||
      !Number.isFinite(otherCost) || otherCost < 0) {
    alert("Enter a quantity from 1 to 10,000 and a non-negative other cost.");
    return;
  }

  // Disable the button while prices are being checked.
  button.disabled = true;
  statusEl().textContent = "Checking live mandi prices…";

  try {

    // Request live prices if an API key has been configured.
    if (DATA_GOV_API_KEY && !DATA_GOV_API_KEY.includes("PASTE_YOUR")) {

      const liveRows = await fetchLivePrices(crop);

      // Display live prices when valid records are available.
      if (liveRows.length) {
        showResults(liveRows, crop, quantity, otherCost, true);

        statusEl().textContent =
          `Live API connected: ${liveRows.length} records received for ${crop}. Transport is still an estimate.`;

      } else {

        // Use sample prices if the API returns no matching records.
        showResults(sampleMarkets, crop, quantity, otherCost, false);

        statusEl().textContent =
          `No live records found for ${crop}; showing clearly labelled demo data instead.`;
      }

    } else {

      // Use sample prices when no API key has been configured.
      showResults(sampleMarkets, crop, quantity, otherCost, false);

      statusEl().textContent =
        "Demo mode: add your Data.gov.in API key in DATA_GOV_API_KEY at the top of the script to request live prices.";
    }

  } catch (error) {

    // Keep the website working if the live API request fails.
    showResults(sampleMarkets, crop, quantity, otherCost, false);
    statusEl().textContent = `Live API unavailable (${error.message}). Showing demo prices so the page still works.`;
  } finally {
    // Re-enable the search button after the request finishes.
    button.disabled = false;
  }
}

// Display initial sample results when the page first opens.
calculate();
</script>

</body>
</html>
