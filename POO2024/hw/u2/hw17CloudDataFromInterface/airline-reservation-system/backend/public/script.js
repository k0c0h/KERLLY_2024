document.getElementById('reservationForm').addEventListener('submit', async function (event) {
    event.preventDefault();
  
    const customerName = document.getElementById('customerName').value;
    const customerEmail = document.getElementById('customerEmail').value;
    const flightOrigin = document.getElementById('flightOrigin').value;
    const flightDestination = document.getElementById('flightDestination').value;
    const pricePerPerson = parseFloat(document.getElementById('pricePerPerson').value);
    const numberOfPeople = parseInt(document.getElementById('numberOfPeople').value);
  
    const totalPrice = pricePerPerson * numberOfPeople;
  
    const data = {
      customerName,
      customerEmail,
      flightOrigin,
      flightDestination,
      pricePerPerson,
      numberOfPeople,
      totalPrice
    };
  
    try {
      const response = await fetch('http://localhost:3000/api/reservations/add', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
      });
  
      if (response.ok) {
        const result = await response.json();
        alert(`Reservation made successfully with ID: ${result._id}`);
      } else {
        alert('Failed to make reservation');
      }
    } catch (error) {
      console.error('Error:', error);
    }
  });
  