document.getElementById('keyboardForm').addEventListener('submit', async (e) => {
    e.preventDefault();

    const keyboard = {
        id: parseInt(document.getElementById('id').value),
        name: document.getElementById('name').value,
        price: parseFloat(document.getElementById('price').value),
        weight: parseFloat(document.getElementById('weight').value),
        amount: parseInt(document.getElementById('amount').value)
    };

    keyboard.totalPrice = keyboard.price * keyboard.amount;
    keyboard.approximatedWeight = keyboard.weight * keyboard.amount;

    const data = {
        id: keyboard.id,
        name: keyboard.name,
        price: keyboard.price,
        weight: keyboard.weight,
        amount: keyboard.amount,
        totalPrice: keyboard.totalPrice,
        approximatedWeight: keyboard.approximatedWeight
    };

    try {
        const response = await fetch('/keyboards/keyboard', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(data)
        });

        if (response.ok) {
            alert('Keyboard added successfully!');
            document.getElementById('keyboardForm').reset();
        } else {
            alert('Failed to add keyboard.');
        }
    } catch (error) {
        console.error('Error:', error);
        alert('An error occurred while adding the keyboard.');
    }
});

document.getElementById('findKeyboardForm').addEventListener('submit', async (e) => {
    e.preventDefault();

    const searchId = parseInt(document.getElementById('searchId').value);

    try {
        const response = await fetch(`/keyboards/keyboard/${searchId}`);
        if (response.ok) {
            const keyboard = await response.json();
            const tableBody = document.getElementById('keyboardTable').getElementsByTagName('tbody')[0];
            tableBody.innerHTML = ''; // Clear previous results

            const row = tableBody.insertRow();
            row.insertCell(0).textContent = keyboard.id;
            row.insertCell(1).textContent = keyboard.name;
            row.insertCell(2).textContent = keyboard.price;
            row.insertCell(3).textContent = keyboard.weight;
            row.insertCell(4).textContent = keyboard.amount;
            row.insertCell(5).textContent = keyboard.totalPrice;
            row.insertCell(6).textContent = keyboard.approximatedWeight;
        } else {
            alert('Keyboard not found.');
        }
    } catch (error) {
        console.error('Error:', error);
        alert('An error occurred while searching for the keyboard.');
    }
});
