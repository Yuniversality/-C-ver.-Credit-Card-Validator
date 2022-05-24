// When page loads, do these functions
window.onload = function pageLoad() {
    console.log("The page has loaded"); 
    addYearOptions();
}

// Function for adding options to the year option select 
function addYearOptions()
{
    let today = new Date();  
    const yearSelect = document.getElementById("expiration_year"); 

    for (let i = 0; i <= 10; i++)
    {
        let newOption = document.createElement("option");
        newOption.textContent = Number(today.getFullYear()) + i;
        yearSelect.append(newOption);
    } 
}

function validateCreditCardNumber()
{
    let userInput = document.getElementById("credit_card_number_input");
    //console.log(userInput.value);
    let inputString = (userInput.value).toString();
    //console.log(inputString.length);
    const input_addon = document.getElementById("credit_card_logo");
    
    if (inputString.length == 1)
    {
        console.log("UserInput length = " + userInput.length);
        //input_addon.setAttribute("src", "../[JavaScript Version] Credit Card Number Validator/img/American_Express_logo_(2018).svg");
        input_addon.src = "../[JavaScript Version] Credit Card Number Validator/img/American_Express_logo_(2018).svg";
    }
    else
    {
        //input_addon.setAttribute("src","");
        input_addon.src = "../[JavaScript Version] Credit Card Number Validator/img/Blue_question_mark_icon.svg";
    }
}

function passesLuhnsAlgorithm(creditCardNumber)
{
    let runningSum = 0;
    
}