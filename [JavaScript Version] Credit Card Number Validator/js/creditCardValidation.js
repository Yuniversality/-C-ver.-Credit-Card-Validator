// When the DOM is ready, run these
$(function() {
    addYearOptions();
});

// Function for adding options to the year option select 
function addYearOptions()
{
    // Get today's date
    let today = new Date();
    // Get the year of today
    let thisYear = today.getFullYear();

    // Add in options for the next decade's years (inclusive) 
    $("#year-select").append("<option value='" + thisYear + "'>" + thisYear + "</option>");
    $("#year-select").append("<option value='" + (thisYear+1) + "'>" + (thisYear+1) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+2) + "'>" + (thisYear+2) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+3) + "'>" + (thisYear+3) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+4) + "'>" + (thisYear+4) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+5) + "'>" + (thisYear+5) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+6) + "'>" + (thisYear+6) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+7) + "'>" + (thisYear+7) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+8) + "'>" + (thisYear+8) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+9) + "'>" + (thisYear+9) + "</option>");
    $("#year-select").append("<option value='" + (thisYear+10) + "'>" + (thisYear+10) + "</option>");

    // Refresh option select so the new values show up
    $("#year-select").selectpicker("refresh");
}

function validateCreditCardNumber()
{
    let userInput = document.getElementById("credit-card-number-input").value;
    
}