## Features

Event Management: Add, edit, and delete events.

Color Coding: Categorize events as "work", "personal", or "others" with distinct colors.

Export Functionality: Export the event list for a specific month in JSON or CSV format.

Persistent Storage: Events are saved in the browser's local storage, ensuring data is retained between sessions.

Interactive UI: A dynamic calendar view with day, week, and month options using FullCalendar.

## Prerequisites

Node.js (version 14 or higher)
npm or yarn

## Installation

1. Clone the repository:
   git clone https://github.com/Adrin-Bershik-C-J/Dynamic-Event-Calendar-Application
   cd Dynamic-Event-Calendar-Application

2. Install dependencies:
   npm install
   or
   yarn install

## Running the App Locally

1. Start the development server:
   npm run dev
   or
   yarn dev

2. Open your browser and navigate to:
   http://localhost:3000

## Exporting Events

1. Click on the Export JSON or Export CSV button in the sidebar to download the events for the current month.

2. The file will be saved with a default name (e.g., events.json or events.csv)

## Technologies Used

React: Front-end library for building user interfaces.

FullCalendar: Calendar library for rendering events.

TypeScript: Adds type safety to JavaScript.

FileSaver.js: Enables exporting files in JSON and CSV formats.

Tailwind CSS: Utility-first CSS framework for styling.

## Deployed Application Link

The app is deployed and accessible at https://dynamic-event-calendar-application-swart.vercel.app/.
