function createDeviceCard(device) {
    // Create the SVG icon element
    var svgIcon = $('<svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-motherboard" viewBox="0 0 16 16">\
    <path d="M11.5 2a.5.5 0 0 1 .5.5v7a.5.5 0 0 1-1 0v-7a.5.5 0 0 1 .5-.5Zm2 0a.5.5 0 0 1 .5.5v7a.5.5 0 0 1-1 0v-7a.5.5 0 0 1 .5-.5Zm-10 8a.5.5 0 0 0 0 1h6a.5.5 0 0 0 0-1h-6Zm0 2a.5.5 0 0 0 0 1h6a.5.5 0 0 0 0-1h-6ZM5 3a1 1 0 0 0-1 1h-.5a.5.5 0 0 0 0 1H4v1h-.5a.5.5 0 0 0 0 1H4a1 1 0 0 0 1 1v.5a.5.5 0 0 0 1 0V8h1v.5a.5.5 0 0 0 1 0V8a1 1 0 0 0 1-1h.5a.5.5 0 0 0 0-1H9V5h.5a.5.5 0 0 0 0-1H9a1 1 0 0 0-1-1v-.5a.5.5 0 0 0-1 0V3H6v-.5a.5.5 0 0 0-1 0V3Zm0 1h3v3H5V4Zm6.5 7a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h2a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5h-2Z"/>\
    <path d="M1 2a2 2 0 0 1 2-2h11a2 2 0 0 1 2 2v11a2 2 0 0 1-2 2H3a2 2 0 0 1-2-2v-2H.5a.5.5 0 0 1-.5-.5v-1A.5.5 0 0 1 .5 9H1V8H.5a.5.5 0 0 1-.5-.5v-1A.5.5 0 0 1 .5 6H1V5H.5a.5.5 0 0 1-.5-.5v-2A.5.5 0 0 1 .5 2H1Zm1 11a1 1 0 0 0 1 1h11a1 1 0 0 0 1-1V2a1 1 0 0 0-1-1H3a1 1 0 0 0-1 1v11Z"/>\
    </svg>');
    var loadingSpinner = $('<div>').addClass('spinner-border').addClass('text-light').addClass("small-spinner")
    // Create a Bootstrap card element for a device
    var card = $('<div>').addClass('card').addClass("device-stats-card").addClass("col");
    var cardBody = $('<div>').addClass('card-body');
    var cardTitle = $('<h5>').addClass('card-title').text(' Device');
    // Prepend the SVG icon to the card title
    cardTitle.prepend(svgIcon);
    var cardTextDevId= $('<p>').addClass('card-text').text('Connected Device Id: ' + device.device_id);
    var cardTextMsgCount = $('<p>').addClass('card-text').text('Total Messages: ' + device.total_message_count);
    cardTextMsgCount.append(loadingSpinner);
    // Append elements to construct the card
    cardBody.append(cardTitle, cardTextDevId, cardTextMsgCount);
    card.append(cardBody);
    return card;
}



function updateMqttInfo() {
    $.ajax({
        url: "/get_mqtt_info",
        dataType: 'json',
        success: function (data) {
            // Clear existing cards
            $('#device-cards-container').empty();

            // Create a card for each device and wrap them in rows
            for (var i = 0; i < data.devices.length; i++) {
                var device = data.devices[i];
                var card = createDeviceCard(device);

                // Create a new row if the number of cards in the current row is a multiple of 2
                if (i % 2 === 0) {
                    var containerRow = $('<div>').addClass('row');
                    $('#device-cards-container').append(containerRow);
                }

                // Append the card to the current row
                containerRow.append(card);
            }
            if (data.devices.length == 0){
                // Create the SVG icon element
                var svgIcon = $('<svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-motherboard" viewBox="0 0 16 16">\
                <path d="M11.5 2a.5.5 0 0 1 .5.5v7a.5.5 0 0 1-1 0v-7a.5.5 0 0 1 .5-.5Zm2 0a.5.5 0 0 1 .5.5v7a.5.5 0 0 1-1 0v-7a.5.5 0 0 1 .5-.5Zm-10 8a.5.5 0 0 0 0 1h6a.5.5 0 0 0 0-1h-6Zm0 2a.5.5 0 0 0 0 1h6a.5.5 0 0 0 0-1h-6ZM5 3a1 1 0 0 0-1 1h-.5a.5.5 0 0 0 0 1H4v1h-.5a.5.5 0 0 0 0 1H4a1 1 0 0 0 1 1v.5a.5.5 0 0 0 1 0V8h1v.5a.5.5 0 0 0 1 0V8a1 1 0 0 0 1-1h.5a.5.5 0 0 0 0-1H9V5h.5a.5.5 0 0 0 0-1H9a1 1 0 0 0-1-1v-.5a.5.5 0 0 0-1 0V3H6v-.5a.5.5 0 0 0-1 0V3Zm0 1h3v3H5V4Zm6.5 7a.5.5 0 0 0-.5.5v1a.5.5 0 0 0 .5.5h2a.5.5 0 0 0 .5-.5v-1a.5.5 0 0 0-.5-.5h-2Z"/>\
                <path d="M1 2a2 2 0 0 1 2-2h11a2 2 0 0 1 2 2v11a2 2 0 0 1-2 2H3a2 2 0 0 1-2-2v-2H.5a.5.5 0 0 1-.5-.5v-1A.5.5 0 0 1 .5 9H1V8H.5a.5.5 0 0 1-.5-.5v-1A.5.5 0 0 1 .5 6H1V5H.5a.5.5 0 0 1-.5-.5v-2A.5.5 0 0 1 .5 2H1Zm1 11a1 1 0 0 0 1 1h11a1 1 0 0 0 1-1V2a1 1 0 0 0-1-1H3a1 1 0 0 0-1 1v11Z"/>\
                </svg>');
                var loadingSpinner = $('<div>').addClass('spinner-border').addClass('text-light').addClass("small-spinner")
                var noDeviceMsg = $('<span>').text(" No Devices, I'll Keep Sensing ");
                $('#device-cards-container').append(noDeviceMsg)
                $('#device-cards-container').prepend(svgIcon);
                $('#device-cards-container').append(loadingSpinner)
            }
        },
        complete: function () {
            // Schedule the next update in 2 seconds
            setTimeout(updateMqttInfo, 5000);
        }
    });
}

// Initial update and subsequent updates
$(document).ready(function () {
    updateMqttInfo();
});
